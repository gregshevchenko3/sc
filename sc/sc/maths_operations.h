#ifndef __MATH_OPERATIONS_H__
#define  __MATH_OPERATIONS_H__

#include <cmath>
#include "matrix_row.hpp"
#include "ErrorHandling.h"

template <typename Tnumeric> Tnumeric pow_operation(Tnumeric base, Tnumeric exp);
template <typename Tnumeric> Tnumeric factorial_operation(Tnumeric n);

/* Модуль числа */
template <typename Tnumeric> void abs_(const matrix_row<Tnumeric>& arglist, matrix_row<Tnumeric>& result);
/* Логарифми */
template <typename Tnumeric> void log_(const matrix_row<Tnumeric>& arglist, matrix_row<Tnumeric>& result);
template <typename Tnumeric> void lg_(const matrix_row<Tnumeric>& arglist, matrix_row<Tnumeric>& result);
template <typename Tnumeric> void ln_(const matrix_row<Tnumeric>& arglist, matrix_row<Tnumeric>& result);

/* Тригонометрія */
template <typename Tnumeric> void sin_(const matrix_row<Tnumeric>& arglist, matrix_row<Tnumeric>& result);
template <typename Tnumeric> void cos_(const matrix_row<Tnumeric>& arglist, matrix_row<Tnumeric>& result);
template <typename Tnumeric> void tg_(const matrix_row<Tnumeric>& arglist, matrix_row<Tnumeric>& result);
template <typename Tnumeric> void ctg_(const matrix_row<Tnumeric>& arglist, matrix_row<Tnumeric>& result);
template <typename Tnumeric> void arcsin_(const matrix_row<Tnumeric>& arglist, matrix_row<Tnumeric>& result);
template <typename Tnumeric> void arccos_(const matrix_row<Tnumeric>& arglist, matrix_row<Tnumeric>& result);
template <typename Tnumeric> void arctg_(const matrix_row<Tnumeric>& arglist, matrix_row<Tnumeric>& result);
template <typename Tnumeric> void arcctg_(const matrix_row<Tnumeric>& arglist, matrix_row<Tnumeric>& result);



#endif