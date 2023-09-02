#include <C:/Embedded/Baitap_1_9_2023/Header/ngaythangnam.h>

static const char *thuTrongTuan(Weekdays days){
    switch(days){
        THU(traNgay,;)
        default: return NULL;
    }
}
Date DATE_ORGIN={3,9,2023};
uint16_t daysOfYear(Date date_count){
    uint16_t countdays=0;
    switch (date_count.month)
    {
        TINHDAY(MONTH_CASE,countdays,date_count.day)
        default: break;
    }
    bool year_special;
    if(date_count.year%4==0){
        if(date_count.year%100==0){
            if(date_count.year%400==0) year_special=true;
            else year_special=false; 
        }
        else year_special=true;
    }
    else year_special=false;
    if(!year_special) return (365-countdays);
    else{
        if(date_count.month<FEBRUARY){
          return (365-countdays);
        }
        else if(date_count.month==FEBRUARY){
            if(date_count.day<DAY_OF_MONTH_FEBRUARY+1) return (365-countdays);
            else return (366-countdays);
        }
        else{
            return (366-countdays);
        }
    }
        

}
uint16_t ngayBuNhuan(uint16_t year_begin,uint16_t year_end){
    uint16_t answer=0;
    answer=(year_end-1)/YEAR_4+(year_end-1)/YEAR_100+(year_end-1)/YEAR_400-((year_begin-1)/YEAR_4+(year_begin-1)/YEAR_100+(year_begin-1)/YEAR_400);
    return answer;
}
void printWeekDay(Date date_value){
    //if the date_value is after the DATE_ORGIN is true; else is false
    int countday=0;
    if(date_value.year>DATE_ORGIN.year){
        countday=((date_value.year-DATE_ORGIN.year)+daysOfYear(date_value)-daysOfYear(DATE_ORGIN))%7;
        countday=countday+ngayBuNhuan(DATE_ORGIN.year,date_value.year);
    }
    else if(date_value.year==DATE_ORGIN.year){
        countday=daysOfYear(date_value)-daysOfYear(DATE_ORGIN);
    }
    else{
        countday=((date_value.year-DATE_ORGIN.year)+daysOfYear(date_value)-daysOfYear(DATE_ORGIN))%7;
        countday=countday+ngayBuNhuan(date_value.year,DATE_ORGIN.year);
    }
    if(countday>0){
            countday%=7;
        }
        else{
            countday%=7;
            countday+=7;
            countday%=7;
        }
    printf("%s",thuTrongTuan(countday));

}

