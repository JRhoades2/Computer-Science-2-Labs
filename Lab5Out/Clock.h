class Clock
{
private:
	int hour;
	int min;
	int sec;


public:
	Clock();
	bool setHour(int hour_val);
	bool setMin(int min_val);
	bool setSec(int sec_val);
	int getHour();
	int getMin();
	int getSec();
	void draw();

};
