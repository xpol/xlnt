// Copyright (c) 2014-2016 Thomas Fussell
// Copyright (c) 2010-2015 openpyxl
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
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, WRISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE
//
// @license: http://www.opensource.org/licenses/mit-license.php
// @author: see AUTHORS file

#include <xlnt/styles/fill.hpp>

namespace xlnt {

fill::fill()
    : type_(type::pattern),
      pattern_type_(pattern_type::none),
      gradient_type_(gradient_type::none),
      rotation_(0),
      gradient_path_left_(0),
      gradient_path_right_(0),
      gradient_path_top_(0),
      gradient_path_bottom_(0)
{
}

fill::type fill::get_type() const
{
    return type_;
}

void fill::set_type(type t)
{
    type_ = t;
}

fill::pattern_type fill::get_pattern_type() const
{
    return pattern_type_;
}

void fill::set_pattern_type(pattern_type t)
{
    type_ = type::pattern;
    pattern_type_ = t;
}

fill::gradient_type fill::get_gradient_type() const
{
    return gradient_type_;
}

void fill::set_gradient_type(gradient_type t)
{
    type_ = type::gradient;
    gradient_type_ = t;
}

void fill::set_foreground_color(const color &c)
{
    foreground_color_ = c;
}

std::experimental::optional<color> &fill::get_foreground_color()
{
    return foreground_color_;
}

const std::experimental::optional<color> &fill::get_foreground_color() const
{
    return foreground_color_;
}

std::experimental::optional<color> &fill::get_background_color()
{
    return background_color_;
}

const std::experimental::optional<color> &fill::get_background_color() const
{
    return background_color_;
}

std::experimental::optional<color> &fill::get_start_color()
{
    return start_color_;
}

const std::experimental::optional<color> &fill::get_start_color() const
{
    return start_color_;
}

std::experimental::optional<color> &fill::get_end_color()
{
    return end_color_;
}

const std::experimental::optional<color> &fill::get_end_color() const
{
    return end_color_;
}

void fill::set_rotation(double rotation)
{
    rotation_ = rotation;
}

double fill::get_rotation() const
{
    return rotation_;
}

std::string fill::to_hash_string() const
{
    std::string hash_string = "fill";
    
    hash_string.append(std::to_string(static_cast<std::size_t>(type_)));

    switch (type_)
    {
    case type::pattern:
    {
        hash_string.append(std::to_string(static_cast<std::size_t>(pattern_type_)));

        hash_string.append(background_color_ ? "1" : "0");

        if (background_color_)
        {
            hash_string.append(std::to_string(background_color_->hash()));
        }

        hash_string.append(background_color_ ? "1" : "0");

        if (background_color_)
        {
            hash_string.append(std::to_string(background_color_->hash()));
        }
        
        break;
    }
    case type::gradient:
    {
        hash_string.append(std::to_string(static_cast<std::size_t>(gradient_type_)));

        if (gradient_type_ == gradient_type::path)
        {
            hash_string.append(std::to_string(gradient_path_left_));
            hash_string.append(std::to_string(gradient_path_right_));
            hash_string.append(std::to_string(gradient_path_top_));
            hash_string.append(std::to_string(gradient_path_bottom_));
        }
        else if (gradient_type_ == gradient_type::linear)
        {
            hash_string.append(std::to_string(rotation_));
        }
        
        hash_string.append(start_color_ ? "1" : "0");

        if (start_color_)
        {
            hash_string.append(std::to_string(start_color_->hash()));
        }
        
        hash_string.append(end_color_ ? "1" : "0");

        if (end_color_)
        {
            hash_string.append(std::to_string(end_color_->hash()));
        }
        
        break;
    }
    default:
    {
        break;
    }
    } // switch (type_)

    return hash_string;
}

double fill::get_gradient_left() const
{
    return gradient_path_left_;
}

double fill::get_gradient_right() const
{
    return gradient_path_right_;
}

double fill::get_gradient_top() const
{
    return gradient_path_top_;
}

double fill::get_gradient_bottom() const
{
    return gradient_path_bottom_;
}

void fill::set_background_color(const color &c)
{
    background_color_ = c;
}

void fill::set_start_color(const color &c)
{
    start_color_ = c;
}

void fill::set_end_color(const color &c)
{
    end_color_ = c;
}

} // namespace xlnt
