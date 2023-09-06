#pragma once

template<typename T>
class autoptr {
    T* ptr = nullptr;

public:
    autoptr() = default;
    ~autoptr() {
        delete ptr;  
    }
    autoptr(T* obj) : ptr(obj) {}
    autoptr(const autoptr& obj) = delete;
    autoptr(autoptr&& obj) noexcept : ptr(obj.ptr) {
        obj.ptr = nullptr;  
    }
    autoptr& operator=(autoptr&& obj) noexcept {
        if (this != &obj) {
            delete ptr;     
            ptr = obj.ptr;  
            obj.ptr = nullptr;
        }
        return *this;
    }
    autoptr& operator=(const autoptr& obj) = delete;
public:
    T* get() {
        return ptr;
    }
    T* operator->() {
        return ptr;
    }
    T operator*() {
        return *ptr;
    }
    void reset(T* obj = nullptr) {
        delete ptr; 
        ptr = obj;
    }
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }
};
