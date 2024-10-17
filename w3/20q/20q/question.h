#pragma once
class question
{
	public:
		question();
		void userAnswer();
		int* getValues();
		int getUser();
		void setAnswer(int input);
		void SetUserAnswer(int UserAnswer);

	protected:
		virtual char getSymobl() = 0;

	private:
		int value1;
		int value2;
		int UserAnswer;
};

