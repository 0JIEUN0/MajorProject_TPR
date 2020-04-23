#include "Date.h"
#include <iostream>
#include <cstring>

Date::Date() {
    Date(0,0,0);
}
Date::Date(int date, int day, int range)
    :date(date),day(day),range(range){
    parseDate();
    this->schedules.reserve(20);
}

void Date::parseDate() {
    string date_str = to_string(this->date);

    for (int i = 0; i < date_str.length(); i++) {
        if (i < 4) {
            str_year += date_str.at(i);
        }
        else if (i < 6) {
            str_month += date_str.at(i);
        }
        else {
            str_day += date_str.at(i);
        }
    }
}
    
void  Date::showSch(string specifier){
    cout << endl;
    if (specifier == "month") {
        // Keyword
        string week;
        cout << str_year<<"."<<str_month<<"."<<str_day<<" ";
        switch (this->day) {
        case 1: week = "SUN"; break;
        case 2: week = "MON"; break;
        case 3: week = "TUE"; break;
        case 4: week = "WED"; break;
        case 5: week = "THU"; break;
        case 6: week = "FRI"; break;
        case 7: week = "SAT"; break;
        }
        cout << "(" << week << ") ";

        for (int i = 0; i < schedules.size(); i++) {
            cout << schedules.at(i).getKeyword();
            if (schedules.size() != 1 && i < schedules.size() - 2)cout << " / ";
        }

    }else if (specifier == "week") {
        // Keyword
        string week;
        cout << str_year<<"."<<str_month<<"."<<str_day<<" ";
        switch(this->day){
            case 1: week = "SUN"; break;
            case 2: week = "MON"; break;
            case 3: week = "TUE"; break;
            case 4: week = "WED"; break;
            case 5: week = "THU"; break;
            case 6: week = "FRI"; break;
            case 7: week = "SAT"; 
        }
        cout << " ("<<week<<") ";
        
        for (int i = 0; i < schedules.size(); i++) {
            cout << schedules.at(i).getKeyword();
            if (schedules.size() != 1 && i < schedules.size() - 2)cout << " / ";	
        }
    }
    else if (specifier == "day") {
        // Detailed information
        string week;
        cout << str_year<<"."<<str_month<<"."<<str_day<<" ";
        switch(this->day){
            case 1: week = "SUN"; break;
            case 2: week = "MON"; break;
            case 3: week = "TUE"; break;
            case 4: week = "WED"; break;
            case 5: week = "THU"; break;
            case 6: week = "FRI"; break;
            case 7: week = "SAT"; 
        }
        cout << "("<<week<<") ";
        for (int i = 0; i < schedules.size(); i++) {
            cout << i+1 <<". ";
            cout << schedules.at(i).getContent() << endl;
        }
    }
    else {
        // Something else entered --> Error
    }
    cout << endl << endl;
}
void  Date::addSch(string content, string keyword){
    this->schedules.push_back(Schedule(content, keyword));
}
void  Date::editSch(int number, string content, string keyword){
    vector<Schedule>::iterator it=this->schedules.begin();
    it=it+(number-1);		//������Ѻ��� ~^^
    schedules.erase(it);
    this->addSch(content,keyword);
}
void  Date::deleteSch(int* num, int len){	
    // manager ���� >>>ū ������ ���ĵ� <<< int �迭 (num) �ѱ�
    vector<Schedule>::iterator it = this->schedules.begin();
    for (int i = 0; i < len; i++) {
        it = it + num[i] - 1;
        schedules.erase(it);
    }
}

int Date::getDate() {
    return this->date; 
}
void  Date::setDate(int date){
    this->date = date;
}
int  Date::getDay(){
    return this->day ;
}
void  Date::setDay(int day) {
    this->day = day;
}
int  Date::getRange() {
    return this->range;
}
void  Date::setRange(int range) {
    this->range=range;
}
vector<Schedule> Date::getSchedules(){
    return this->schedules;
}

int Date::getLength(){
    return this->schedules.size();
}
string Date::getDayNormFormat() {
    string tmp = "";
    switch (this->day) {
    case 1:
        tmp = "Sun";
        break;
    case 2:
        tmp = "Mon";
        break;
    case 3:
        tmp = "Tue";
        break;
    case 4:
        tmp = "Wed";
        break;
    case 5:
        tmp = "Thr";
        break;
    case 6:
        tmp = "Fri";
        break;
    case 7:
        tmp = "Sat";
        break;
    default:
        tmp = "Unk";
        break;
    }
    return tmp;
}