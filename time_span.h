#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <string>

class TimeSpan
{
public:
 TimeSpan(int seconds);
 TimeSpan(int minutes, int seconds);
 TimeSpan(int hours, int minutes, int seconds);

 int hours() const; // return the number of hours as an int
 int minutes() const; // return the number of minutes as an int
 int seconds() const; // return the number of seconds as an int
 void set_time(int hours, int minutes, int seconds); // set hours, minutes, seconds

 TimeSpan operator+(const TimeSpan& b) const;

 TimeSpan operator-(const TimeSpan& b) const;

 TimeSpan& operator+=(const TimeSpan& b);

 TimeSpan& operator-=(const TimeSpan& b);

 TimeSpan operator-() const;

 bool operator==(const TimeSpan& b) const;

 bool operator!=(const TimeSpan& b) const;

 bool operator<(const TimeSpan& b) const;

 bool operator<=(const TimeSpan& b) const;

 bool operator>(const TimeSpan& b) const;

 bool operator>=(const TimeSpan& b) const;

 friend std::istream& operator>>(std::istream& is, TimeSpan& t);

private:
    int hours_;
    int minutes_;
    int seconds_;

    void normalize();
};
std::ostream& operator<<(std::ostream& os, const TimeSpan& t);
#endif