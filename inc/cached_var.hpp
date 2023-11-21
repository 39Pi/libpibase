#pragma once

#include <cassert>
#include <functional>
#include "checkers.hpp"

namespace pibase {

template<typename T>
struct CachedVar {
	CachedVar() : _callback(nullptr) {}
	CachedVar(std::function<T()> callback) : _callback(callback) {}
	constexpr bool isCached() {
		return _set;
	}

	//! Clear the cached variable. If it is a shared_ptr, the reference of this shared ptr
	void clear() {
		_set = false;

		if(::pibase::is_shared_ptr<T>::value) {
			// If this is a shared pointer, delete it.
			_var.reset();
		}
	}

	constexpr void set(const T& val) {
		_var = val;
		_set = true;
	}

	T& get() {
		if(!_set && _callback) {
			_var = _callback();
			_set = true;
		}
		assert(_set);
		
		// We do not assert on _var here; it should be checked by the next thing down the line.
		return _var;
	}

private:
	std::function<T()> _callback;
	T _var;
	bool _set;
};

}
