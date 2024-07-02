wbg-color
=========

[![CodeFactor](https://www.codefactor.io/repository/github/jorengarenar/wbg-color/badge)](https://www.codefactor.io/repository/github/jorengarenar/wbg-color)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/bae7fe9310384ed98608c9b2ff2f8733)](https://app.codacy.com/gh/Jorengarenar/wbg-color/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=Jorengarenar_wbg-color&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=Jorengarenar_wbg-color)

Even more simplified wallpaper application for Wayland compositors
implementing the layer-shell protocol.

`wbg-color` takes a single command line argument: color hex code.

wbg-color is based on [wbg](https://codeberg.org/dnkl/wbg).

## Dependencies

* [pixman](https://cgit.freedesktop.org/pixman/)
* [Wayland](https://wayland.freedesktop.org/)
* GNU C compiler (e.g. [GCC](https://gcc.gnu.org/) or [Clang](https://clang.llvm.org/)) _(make)_
* [GNU make](https://www.gnu.org/software/make/) _(make)_
* [pkg-config](https://www.freedesktop.org/wiki/Software/pkg-config/) _(make)_
* [wayland-protocols](https://gitlab.freedesktop.org/wayland/wayland-protocols) _(make)_

## Building

```sh
$ make
```

The program will be created at `build/bin/wbg-color`
