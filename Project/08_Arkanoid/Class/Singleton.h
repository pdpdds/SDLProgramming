//
//  Singleton.h
//  Arkanoid
//
//  Created by Maciej Żurad on 11/19/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#ifndef __Arkanoid__Singleton__
#define __Arkanoid__Singleton__

#include <iostream>
#include <cassert>

template <typename T> class Singleton
{
    static T* ms_singleton;
    
public:
    Singleton( void )
    {
        assert( !ms_singleton );
        ms_singleton = static_cast <T*> (this);
    }
    
    ~Singleton() { assert(ms_singleton); ms_singleton = 0; }
    static T& GetSingleton() { assert(ms_singleton); return *ms_singleton; }
    static T* GetSingletonPtr() { return ms_singleton; }
};

template <typename T> T* Singleton <T>::ms_singleton = 0;



#endif /* defined(__Arkanoid__Singleton__) */
