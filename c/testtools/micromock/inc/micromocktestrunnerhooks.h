/*
Microsoft Azure IoT Device Libraries
Copyright (c) Microsoft Corporation
All rights reserved. 
MIT License
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated 
documentation files (the Software), to deal in the Software without restriction, including without limitation 
the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, 
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED *AS IS*, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED 
TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
IN THE SOFTWARE.
*/

#ifndef MICROMOCCKTESTRUNNERHOOKS_H
#define MICROMOCCKTESTRUNNERHOOKS_H

#pragma once

#include <stdlib.h>
#ifdef _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#ifndef MOCK_ASSERT

#include "stdafx.h"
#include "testrunnerswitcher.h"

#define MOCK_ASSERT(expected, actual, assertString)     ASSERT_ARE_EQUAL((expected), (actual), (assertString))
#define MOCK_FAIL(expression)                           ASSERT_FAIL(expression)

#ifndef MBED_BUILD_TIMESTAMP
#define MOCK_THROW(mockException)                       throw(mockException)
#else
#define MOCK_THROW(mockException)
#endif

#else // MOCK_ASSERT
#define MOCK_THROW(...)
#endif // MOCK_ASSERT

#endif // MICROMOCCKTESTRUNNERHOOKS_H
