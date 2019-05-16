#ifndef EXCEPTIONDEF
#define EXCEPTIONDEF

#include <string>
#include <iostream>

class Exception	{
	private:
		std::string mTag, mProblem;
	public:
		Exception();
		Exception(std::string tagString, std::string probString);
		void PrintDebug() const;

		void SetMTag(std::string tagString);
		void SetMProblem(std::string probString);
};

#endif //EXCEPTIONDEF
