#pragma once

#include <vector>
template <typename Tnumeric>
struct matrix_row : std::vector<Tnumeric> {
	explicit matrix_row() : std::vector<Tnumeric>() {};
	explicit matrix_row(std::size_t n) : std::vector<Tnumeric>(n) {};
	~matrix_row(){};

	matrix_row operator-() {
		matrix_row res(this->size());
		auto it = this->begin(), it_r = res.begin();
		while (it != this->end()) *it_r++ = -*it++;
		return res;
	};
	matrix_row& operator+=(const matrix_row& right) {
		auto it_t = this->begin();
		auto it_r = right.begin();
		while (it_t != this->cend()) *it_t++ += *it_r++;
		if (this->size() < right.size()) {
			while (it_r != right.cend()) this->push_back(*it_r++);
		}
		return *this;
	};
	matrix_row& operator-=(const matrix_row& right) {
		auto it_t = this->begin();
		auto it_r = right.begin();
		while (it_t != this->cend()) *it_t++ -= *it_r++;
		if (this->size() < right.size()) {
			while (it_r != right.cend()) this->push_back(-*it_r++);
		}
		return *this;
	};
	matrix_row& operator/=(const matrix_row& right) {
		auto it_t = this->begin();
		auto it_r = right.begin();
		while (it_t != this->cend()) *it_t++ /= *it_r++;
		if (this->size() < right.size()) {
			while (it_r++ != right.cend()) this->push_back(0);
		}
		return *this;
	};
	/* Добуток Адамара.*/
	matrix_row& operator*=(const matrix_row& right) {
		auto it_t = this->begin();
		auto it_r = right.begin();
		while (it_t != this->cend()) *it_t++ *= *it_r++;
		if (this->size() < right.size()) {
			while (it_r++ != right.cend()) this->push_back(0);
		}
		return *this;
	};
	
};