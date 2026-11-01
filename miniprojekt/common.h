/*
 * common.h
 *
 *  Created on: 30.10.2026
 *      Author: n3034770
 */

#ifndef COMMON_H_
#define COMMON_H_

long zeilenkosten(int zb, int b);

int zeilenbreite(const std::vector<std::string>& text, int start, int ende);

std::vector<int> umbruch(std::vector<std::string>& text, int b);

long gesamtkosten(const std::vector<std::string>& text,
		const std::vector<int>& zeilen, int b);

void print_umbruch(const std::vector<std::string>& text,
		const std::vector<int>& zeilen, long& cost, bool& format_cost, int& b);


#endif /* COMMON_H_ */
