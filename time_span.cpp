#include "time_span.h"
#include <iostream>

 TimeSpan::TimeSpan(int seconds)
    :hours_(0), minutes_(0), seconds_(seconds)
    {this->normalize();}

 TimeSpan::TimeSpan(int minutes, int seconds)
    :hours_(0), minutes_(minutes), seconds_(seconds)
    {this->normalize();}

 TimeSpan::TimeSpan(int hours, int minutes, int seconds) 
    :hours_(hours), minutes_(minutes), seconds_(seconds)
    {this->normalize();}


 void TimeSpan::normalize()
 {
    int total = (hours_ * 3600) + (minutes_ * 60) + seconds_;
    hours_ = total / 3600;
    total %= 3600;
    minutes_ = total / 60;
    total %= 60;
    seconds_ = total;
 }

 int TimeSpan::hours() const
 {
    return hours_;
 }

 int TimeSpan::minutes() const
 {
    return minutes_;
 }

 int TimeSpan::seconds() const
 {
    return seconds_;
 }

 void TimeSpan::set_time(int hours, int minutes, int seconds)
 {
    hours_ = hours;
    minutes_ = minutes;
    seconds_ = seconds;
 }

 TimeSpan TimeSpan::operator+(const TimeSpan& b) const
 {
    return TimeSpan(hours_ + b.hours_, minutes_ + b.minutes_, seconds_ + b.seconds_);
 }

 TimeSpan TimeSpan::operator-(const TimeSpan& b) const
 {
    return TimeSpan(hours_ - b.hours_, minutes_ - b.minutes_, seconds_ - b.seconds_);
 }

 TimeSpan& TimeSpan::operator+=(const TimeSpan& b)
 {
    hours_ += b.hours_;
    minutes_ += b.minutes_;
    seconds_ += b.seconds_;
    (*this).normalize();
    return *this;
 }

 TimeSpan& TimeSpan::operator-=(const TimeSpan& b)
 {
    hours_ -= b.hours_;
    minutes_ -= b.minutes_;
    seconds_ -= b.seconds_;
    (*this).normalize();
    return *this;
 }

 TimeSpan TimeSpan::operator-() const
 {
    return TimeSpan(-hours_, -minutes_, -seconds_);
 }

 bool TimeSpan::operator==(const TimeSpan& b) const
 {
    return ((hours_ * 3600) + (minutes_ * 60) + seconds_) == ((b.hours_ * 3600) + (b.minutes_ * 60) + b.seconds_);
 }

 bool TimeSpan::operator!=(const TimeSpan& b) const
 {
    return ((hours_ * 3600) + (minutes_ * 60) + seconds_) != ((b.hours_ * 3600) + (b.minutes_ * 60) + b.seconds_);
 }

 bool TimeSpan::operator<(const TimeSpan& b) const
 {
    return ((hours_ * 3600) + (minutes_ * 60) + seconds_) < ((b.hours_ * 3600) + (b.minutes_ * 60) + b.seconds_);
 }

 bool TimeSpan::operator<=(const TimeSpan& b) const
 {
    return ((hours_ * 3600) + (minutes_ * 60) + seconds_) <= ((b.hours_ * 3600) + (b.minutes_ * 60) + b.seconds_);
 }

 bool TimeSpan::operator>(const TimeSpan& b) const
 {
    return ((hours_ * 3600) + (minutes_ * 60) + seconds_) > ((b.hours_ * 3600) + (b.minutes_ * 60) + b.seconds_);
 }

 bool TimeSpan::operator>=(const TimeSpan& b) const
 {
    return ((hours_ * 3600) + (minutes_ * 60) + seconds_) >= ((b.hours_ * 3600) + (b.minutes_ * 60) + b.seconds_);
 }

std::ostream& operator<<(std::ostream& os, const TimeSpan& t)
{
    os << "Hours: " << t.hours() << ", Minutes: " << t.minutes() << ", Seconds: " << t.seconds() << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, TimeSpan& t)
{
    is >> t.hours_, t.minutes_, t.seconds_;
    return is;
}