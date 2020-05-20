#pragma once

#include "functionality.hpp"


/**
 * ����� �������.
 * ����� ������ ������ �������� �� ������� ��������, � ��������� �� �����, � ����� ���������� ���������.
 * ����� ������ ������� �������� �� ������ ������, ������ �� � ���, �� �� ������ ���������.
 * ��� ���� ����� ������ ������� ���� ������� ��������, ���� ����� �������� �����, �� � ���������.
 */

char* function_(char * expression, matrix_row<double>& result);
template <typename Tnumeric> char* subexpression(char* subexpression, Tnumeric& result);
template <typename Tnumeric> char* unary_minus_(char* expression, Tnumeric& result);
template <typename Tnumeric> char* white_spaces_(char* expression, Tnumeric& result);
template <typename Tnumeric> char* number_(char* expression, Tnumeric& result);
template <typename Tnumeric> char* factorial_(char* expression, Tnumeric& result);
template <typename Tnumeric> char* pow_(char* expression, Tnumeric& result);
template <typename Tnumeric> char* factors_(char* expression, Tnumeric& result);
template <typename Tnumeric> char* addings_(char* expression, Tnumeric& result);
template <typename Tnumeric> char* comma_(char* expression, Tnumeric& result);
/* ����� ����� � ����� ������� */
template <typename Tnumeric> Tnumeric execute(char* expression);

#include "parsers.impl.hpp"
