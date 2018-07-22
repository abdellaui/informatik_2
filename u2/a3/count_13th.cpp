#include "Weekday_statistics.hpp"
Weekday_statistics count_13th(int start_year, int year_offset){
  Weekday_statistics obj; // Ruckgabewert init.
  int tageImMonat;
  int wochentag = 1;
  const int arrTageImMonat[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  // Tage der Monate
  for(int k = 0; k<=year_offset; k++){ // Schleife für offset
      for(int i=1; i<=12; i++){  // Schleife für 12 Monate in einem Jahr
          tageImMonat = arrTageImMonat[i-1];  // Anzahl Tage im Monat via Array-Index-1 ermitteln
          if(i==2){  // Wenn Monat = Februar -> Schaltjahrprüfung
              if ((start_year % 400) == 0){
                tageImMonat = 29;
              }else if ((start_year % 100) == 0){
                tageImMonat = 28;
              }else if ((start_year % 4) == 0){
                tageImMonat = 29;
              }
          }
          for(int x=1; x <= tageImMonat; x++){  // Schleife für Tage im Monat
            if(x==13){  // Wenn Tag = 13 dann, -- selbsterklärend --
              switch(wochentag){
              case 1: obj.set_monday_value(obj.get_monday_value()+1);
                  break;
              case 2: obj.set_tuesday_value(obj.get_tuesday_value()+1);
                  break;
              case 3: obj.set_wednesday_value(obj.get_wednesday_value()+1);
                  break;
              case 4: obj.set_thursday_value(obj.get_thursday_value()+1);
                  break;
              case 5: obj.set_friday_value(obj.get_friday_value()+1);
                  break;
              case 6: obj.set_saturday_value(obj.get_saturday_value()+1);
                  break;
              case 7: obj.set_sunday_value(obj.get_sunday_value()+1);
                  break;
              }
            }
            wochentag = (wochentag%7)+1; // 7er-Periode [1,7]
          }
      }
      start_year++;
  }
  return obj;
}
