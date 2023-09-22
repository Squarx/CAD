# Тестовое задание на позицию C++ разработчика

## CMake (Для удобного запуска в CLion)

## Цели в Makefile

Собирает и запускает программу

```
make build
```

Собирает динамическую библиотеку, устанавливает на сессию запуска LD_LIBRARY_PATH и запускает программу

```
make build_dynamic
```

При помощи clang-format форматирует код по Google style

```
make style
```

Для систем с установленным Valgrind позволяет посмотреть на утечки и ошибки по памяти

```
make check_valgrind
```

Удалят все лишние файлы

```
make clean
```

Создает динамическую библиотеку !(Не устанавливает LD_LIBRARY_PATH)

```
make library
```

### Task:

### Design a small program in C++ that would implement support of 3D curves hierarchy.

1. Support a few types of 3D geometric curves – circles, ellipses and 3D helixes. (Simplified
   definitions are below). Each curve should be able to return a 3D point and a first derivative (3D
   vector) per parameter t along the curve.
2. Populate a container (e.g. vector or list) of objects of these types created in random manner with
   random parameters.
3. Print coordinates of points and derivatives of all curves in the container at t=PI/4.
4. Populate a second container that would contain only circles from the first container. Make sure the
   second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
5. Sort the second container in the ascending order of circles’ radii. That is, the first element has the
   smallest radius, the last - the greatest.
6. Compute the total sum of radii of all curves in the second container.
7. Split implementation into a library of curves (.dll or .so) and executable which uses API of this
   library.

Curve definitions:

- All curves are parametrically defined, i.e. a point is calculated using some C(t) formula.
- Circle is planar in the plane XoY (i.e. all Z-coordinates are 0) and is defined by its radius.
- Ellipse is planar in the plane XoY and is defined by its two radii, along X and Y axes.
- Helix is spatial and is defined by its radius and step (see the figure below). It takes 2 * PI in
  parametric space to make a round, i.e. any point on helix satisfies the condition C(t + 2*PI) = C(t) +{0, 0, step}.
