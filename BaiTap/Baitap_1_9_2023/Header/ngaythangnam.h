#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#define THU(X,S) \
    X(Monday) S      \
    X(Tuesday) S      \
    X(Wednesday) S      \
    X(Thursday) S      \
    X(Friday) S      \
    X(Saturday) S      \
    X(Sunday) S
#define traNgay(D) case D: return #D
typedef enum{
    Monday=1,
    Tuesday=2,
    Wednesday=3,
    Thursday=4,
    Friday=5,
    Saturday=6,
    Sunday=0,
}Weekdays;
typedef enum{
    JANUARY=1,
    FEBRUARY=2,
    MARCH=3,
    APRIL=4,
    MAY=5,
    JUNE=6,
    JULY=7,
    AUGUST=8,
    SEPTEMBER=9,
    OCTOBER=10,
    NOVEMBER=11,
    DECEMBER=12
}Months;
#define DAY_OF_MONTH_JANUARY         31
#define DAY_OF_MONTH_FEBRUARY        28
#define DAY_OF_MONTH_MARCH           31
#define DAY_OF_MONTH_APRIL           30
#define DAY_OF_MONTH_MAY             31
#define DAY_OF_MONTH_JUNE            30
#define DAY_OF_MONTH_JULY            31
#define DAY_OF_MONTH_AUGUST          31
#define DAY_OF_MONTH_SEPTEMBER       30
#define DAY_OF_MONTH_OCTOBER         31
#define DAY_OF_MONTH_NOVEMBER        30
#define DAY_OF_MONTH_DECEMBER        31
#define YEAR_4                       4
#define YEAR_100                     100
#define YEAR_400                     400

#define TINHDAY(X,countday,days)    \
    X(JANUARY)       countday=countday+DAY_OF_MONTH_JANUARY  -days;days=0;  \
    X(FEBRUARY)      countday=countday+DAY_OF_MONTH_FEBRUARY -days;days=0;  \
    X(MARCH)         countday=countday+DAY_OF_MONTH_MARCH    -days;days=0;  \
    X(APRIL)         countday=countday+DAY_OF_MONTH_APRIL    -days;days=0;  \
    X(MAY)           countday=countday+DAY_OF_MONTH_MAY      -days;days=0;  \
    X(JUNE)          countday=countday+DAY_OF_MONTH_JUNE     -days;days=0;  \
    X(JULY)          countday=countday+DAY_OF_MONTH_JULY     -days;days=0;  \
    X(AUGUST)        countday=countday+DAY_OF_MONTH_AUGUST   -days;days=0;  \
    X(SEPTEMBER)     countday=countday+DAY_OF_MONTH_SEPTEMBER-days;days=0;  \
    X(OCTOBER)       countday=countday+DAY_OF_MONTH_OCTOBER  -days;days=0;  \
    X(NOVEMBER)      countday=countday+DAY_OF_MONTH_NOVEMBER -days;days=0;  \
    X(DECEMBER)      countday=countday+DAY_OF_MONTH_DECEMBER -days;days=0;  
#define MONTH_CASE(X) case X  :  
typedef struct{
    uint8_t day;
    uint8_t month;
    uint16_t year;
}Date;
uint16_t daysOfYear(Date date_count);
static const char *thuTrongTuan(Weekdays days);
void printWeekDay(Date date_value);
#endif // NGAYTHANGNAM_H