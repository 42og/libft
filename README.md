<p align="center">
  <img src="https://pbs.twimg.com/media/DQl3AJ1WsAEwl_C.jpg"/><br>
  <a href="https://travis-ci.com/42og/libft" title="Build status">
     <img src="https://travis-ci.org/42og/libft.svg?branch=master">
  </a>
</p>

# Libft - General purpose library

## Goals
- Perform runtime arguments checks if DEBUG is defined to provide great
development experience.
- Portability in mind.
- Use standard functions if `FT_ALLOW_MEMSET` is defined for instance or a
custom implementation if not.
- Data structures and routines for strings, arrays, linked lists.
- Restrict features accordingly with standard functions availability.

## A bit of context
42 projects main rules:
- There's a very restricted set of standard functions we're allowed to use.
- Most global variables are forbidden unless you cannot do without it.
- Custom functions cannot take more than 4 parameters.
- A custom function is 25 lines max.
- A line is 80 columns max.
- Custom macros shall not have as a primary purpose to bypass the above rules.

## How to Use
- Add -Ilibft/includes in your compiling options, then you can use headers as if
they were in the same folder as your .c
