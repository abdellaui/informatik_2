#include "Weekday_statistics.hpp"

Weekday_statistics::Weekday_statistics(){
    this->monday = 0;
    this->tuesday = 0;
    this->wednesday = 0;
    this->thursday = 0;
    this->friday = 0;
    this->saturday = 0;
    this->sunday = 0;
};

// SETTER
void Weekday_statistics::set_monday_value(int x){
    this->monday = x;
    };
void Weekday_statistics::set_tuesday_value(int x){
    this->tuesday = x;
    };
void Weekday_statistics::set_wednesday_value(int x){
    this->wednesday = x;
    };
void Weekday_statistics::set_thursday_value(int x){
    this->thursday = x;
    };
void Weekday_statistics::set_friday_value(int x){
    this->friday = x;
    };
void Weekday_statistics::set_saturday_value(int x){
    this->saturday = x;
    };
void Weekday_statistics::set_sunday_value(int x){
    this->sunday = x;
    };

// GETTER
int Weekday_statistics::get_monday_value(){
    return this->monday;
    };
int Weekday_statistics::get_tuesday_value(){
    return this->tuesday;
    };
int Weekday_statistics::get_wednesday_value(){
    return this->wednesday;
    };
int Weekday_statistics::get_thursday_value(){
    return this->thursday;
    };
int Weekday_statistics::get_friday_value(){
    return this->friday;
    };
int Weekday_statistics::get_saturday_value(){
    return this->saturday;
    };
int Weekday_statistics::get_sunday_value(){
    return this->sunday;
    };
