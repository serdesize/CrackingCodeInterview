#pragma once

#include <assert.h> 
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <string>

#include "Runner.h"

class Chap1 : Runner 
{

private:
	void q1();
	void q1_variant();
	void q2();
	void q3();
	void q4();
	void q5();
	void q6();
	void q7();
	void q8();
	void q9();

public:
	void Run() override;
};