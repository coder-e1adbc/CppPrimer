struct LongDouble {
	LongDouble(double = 0.0);
	operator double();
	operator float();
};

LongDouble ldObj;
int ex1 = ldObj;	// error: conversion from 'LongDouble' to 'int' is ambiguous
					// ldObj -> double -> int
					// ldObj -> float -> int
float ex2 = ldObj;
