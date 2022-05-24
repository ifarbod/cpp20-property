// Copyright (c) 2022 iFarbod. All Rights Reserved.
//
// SPDX-License-Identifier: Unlicense

#pragma once

#include <functional>

namespace zsl
{

template <typename T>
class Property
{
public:
    using Getter = std::function<const T&(T&)>;
    using Setter = std::function<void(T&, T)>;

    struct GetterSetter
    {
        Getter get;
        Setter set;
    };

    constexpr Property(T& ref, GetterSetter gettersetter =
        {
            .get = [](auto& var) constexpr { return var;},
            .set = [](auto& var, auto value) { var = value; }
        }) noexcept
        : m_ref(ref), m_gettersetter(gettersetter)
    {}

    constexpr operator T() const noexcept
    {
        return m_gettersetter.get == nullptr ? m_ref : m_gettersetter.get(m_ref);
    }

    constexpr T& operator=(T value) noexcept
    {
        if (m_gettersetter.set != nullptr)
        {
            m_gettersetter.set(m_ref, value);
        }

        return m_ref;
    }

private:
    T& m_ref;
    GetterSetter m_gettersetter;
};

}  // namespace zsl
