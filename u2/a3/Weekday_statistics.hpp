#ifndef WEEKEND 
#define WEEKEND
class Weekday_statistics{
        int monday;
        int tuesday;
        int wednesday;
        int thursday;
        int friday;
        int saturday;
        int sunday;
    public:
        Weekday_statistics();
        // SETTER
        void set_monday_value(int);
        void set_tuesday_value(int);
        void set_wednesday_value(int);
        void set_thursday_value(int);
        void set_friday_value(int);
        void set_saturday_value(int);
        void set_sunday_value(int);
        // GETTER
        int get_monday_value();
        int get_tuesday_value();
        int get_wednesday_value();
        int get_thursday_value();
        int get_friday_value();
        int get_saturday_value();
        int get_sunday_value();
};
#endif