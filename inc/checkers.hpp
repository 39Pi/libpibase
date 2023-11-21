#pragma once

#include <memory>
#include <type_traits>

namespace pibase {

// std::is_pointer implementation.
// We reimplement this here, since we want to specfically detect a few other things as well (mainly std::shared_ptr)

template<class T>
struct is_pointer : std::false_type {};

template<class T>
struct is_pointer<T*> : std::true_type {};
template<class T>
struct is_pointer<T* const> : std::true_type {};
template<class T>
struct is_pointer<T* volatile> : std::true_type {};
template<class T>
struct is_pointer<T* const volatile> : std::true_type {};
template<class T>
struct is_pointer<std::shared_ptr<T>> : std::true_type {};


template<class T>
struct is_shared_ptr : std::false_type {};
template<class T>
struct is_shared_ptr<std::shared_ptr<T>> : std::true_type {};


}
