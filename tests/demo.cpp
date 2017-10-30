// Copyright (c) 2008-2014, Andrew Walker
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.'
// extern "C"
// {
// #include "dubins_curve/dubins.h"
// }
#include "dubins_curve/dubins.hpp"
#include <stdio.h>

int printConfiguration(std::vector<double> q, double x, void* user_data) {
    printf("%f,%f,%f,%f\n", q[0], q[1], q[2], x);
    return 0;
}

int main()
{
    std::vector<double> q0 = { 0,0,0 };
    std::vector<double> q1 = { 4,4,3.142 };
    DubinsPath path;
    dubins_init( q0, q1, 1.0, path);

    printf("#x,y,theta,t\n");
    dubins_path_sample_many( path, printConfiguration, 0.1, NULL);

    return 0;
}