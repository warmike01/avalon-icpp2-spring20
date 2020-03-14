#pragma once
#include <iostream>
namespace ext
{
enum class Month
{
January = 1,
February,
March,
April,
May,
June,
July,
August,
September,
October,
Novemver,
December
};

enum class DateFormat
{
MonthAsInt,
MonthAsString
};

enum class Season
{
Winter,
Spring,
Summer,
Autumn
};

enum class SortBy
{
Date,
Season
};

struct Date
{
int year;
Month month;
int day;
};

struct TimeDelta
{
int delta;
};

/*----------homework-04----------*/
/*
Возвращает Юлианскую дату
https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0
раздел "Вычисление номера юлианского дня (JDN) по дате григорианского календаря"
Тестовые данныеОжидаемый результат
1.12.2018 2458454
1.1.2018 2458120
1.6.2000 2451697
21.12.2012 2456283
*/
TimeDelta countJND(Date date)
{
    int a=(14-static_cast<int>(date.month))/12;
    int y = date.year + 4800 - a;
    int m=static_cast<int>(date.month)+12*a+3;
    TimeDelta JND;
    JND.delta=date.day+(153*m+2)/5+365*y+y/4+y/400-y/100-32045;
}
Date JND_to_date(TimeDelta JND)
{
    int a=JND.delta+32044;
    int b=(4*a+3)/146097;
    int c=a-146097*b/4;
    int d=(4*c+3)/1462;
    int e= c-1461*d/4;
    int m=(5*e+2)/153;
    Date data;
    data.day=e-(153*m+2)/5+1;
    data.month=static_cast<Month> (m+3-12*(m/10));
    data.year=100*b+d-4800+m/10;
    return data;
}
/*
Рассчитывает количество дней между двумя датами.
При реализвации используйте CountJND
*/
TimeDelta countDistance(Date from, Date to)
{
    TimeDelta dist;
    dist.delta=abs(countJND(from).delta - countJND(to).delta);
    return dist;
}

void printMonthAsString(Month month)
{
switch (month)
{
case Month::January:
std::cout << "January";
break;
case Month::February:
std::cout << "February";
break;
case Month::March:
std::cout << "March";
break;
case Month::April:
std::cout << "April";
break;
case Month::May:
std::cout << "May";
break;
case Month::June:
std::cout << "June";
break;
case Month::July:
std::cout << "July";
break;
case Month::August:
std::cout << "August";
break;
case Month::September:
std::cout << "September";
break;
case Month::October:
std::cout << "October";
break;
case Month::Novemver:
std::cout << "Novemver";
break;
case Month::December:
std::cout << "December";
break;
default:
std::cout << "Unknown month";
break;
}
}

/*
Выводит в консоль
*/
void print(Month month, DateFormat format = DateFormat::MonthAsInt)
{
if (format == DateFormat::MonthAsInt)
{
std::cout << static_cast<int>(month);
}
else if (format == DateFormat::MonthAsString)
{
printMonthAsString(month);
}
else
{
std::cout << "Wrong format!";
}
}

void print(Date data, DateFormat format = DateFormat::MonthAsInt)
{
std::cout << data.day << " ";
print(data.month, format);
std::cout << " " << data.year;
}

void print(TimeDelta delta)
{
    Date convert;
    convert = JND_to_date(delta);
    print(convert);
}
/*
Возвращает сезон (зима, весна, лето, осень) передаваемой даты
*/
Season getSeason(Month month)
{
    switch (month)
    {
        case Month::December : return Season::Winter; break;
        case Month::January : return Season::Winter; break;
        case Month::February : return Season::Winter; break;
        case Month::March : return Season::Spring; break;
        case Month::April : return Season::Spring; break;
        case Month::May : return Season::Spring; break;
        case Month::June : return Season::Summer; break;
        case Month::July : return Season::Summer; break;
        case Month::August : return Season::Summer; break;
        case Month::September : return Season::Autumn; break;
        case Month::October : return Season::Autumn; break;
        case Month::Novemver : return Season::Autumn; break;
    }
}
Season getSeason(Date date)
{
    return getSeason(date.month);
}

/*
Написать перегрузку для следующих логических операторов
*/
bool operator == (const Date lhs, const Date rhs)
{
    if (lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year) {return true;}
    else {return false;}
}
bool operator != (const Date lhs, const Date rhs)
{
    return !(lhs == rhs);
}
bool operator < (const Date lhs, const Date rhs)
{
    if (countJND(lhs).delta < countJND(rhs).delta ) {return true;}
    else {return false;}
}
bool operator >= (const Date lhs, const Date rhs)
{
    return !(lhs < rhs);
}
bool operator > (const Date lhs, const Date rhs)
{
    if (countJND(lhs) .delta> countJND(rhs) .delta) {return true;}
    else {return false;}
}
bool operator <= (const Date lhs, const Date rhs)
{
    return !(lhs > rhs);
}



/*
Написать перегрузку для следующих арифметических операторов
*/
Date operator + (const Date date, const TimeDelta delta)
{
    TimeDelta JND;
    JND.delta=countJND(date).delta + delta.delta;
    return JND_to_date(JND);
}
Date operator + (const TimeDelta delta, const Date date)
{
    return date+delta;
}
TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs)
{
    TimeDelta result;
    result.delta = lhs.delta + rhs.delta;
    return result;
}
TimeDelta operator * (const TimeDelta delta, int multiplier)
{
    TimeDelta result;
    result.delta = delta.delta * multiplier;
    return result;
}
TimeDelta operator * (int multiplier, const TimeDelta delta)
{
    return delta * multiplier;
}

/*----------homework-05----------*/

TimeDelta operator ++ (TimeDelta& delta)
{
    delta.delta++;
    return delta;
}
TimeDelta operator ++ (TimeDelta& delta, int)
{
   TimeDelta temp=delta;
    delta.delta++;
    return temp;
}

TimeDelta operator -- (TimeDelta& delta)
{
     delta.delta--;
    return delta;
}
TimeDelta operator -- (TimeDelta& delta, int)
{
    TimeDelta temp=delta;
    delta.delta--;
    return temp;
}
Date operator ++ (Date& delta)
{
    TimeDelta JND=countJND(delta);
     JND.delta++;
     delta=JND_to_date(JND);
    return delta;
}
Date operator ++ (Date& delta, int)
{
     Date temp=delta;
      TimeDelta JND=countJND(temp);
     JND.delta++;
     delta=JND_to_date(JND);
    temp=JND_to_date(JND);
    return temp;
}

Date operator -- (Date& delta)
{
    TimeDelta JND=countJND(delta);
     JND.delta++;
     delta=JND_to_date(JND);
    return delta;
}
Date operator -- (Date& delta, int)
{
     Date temp=delta;
      TimeDelta JND=countJND(temp);
     JND.delta--;
     delta=JND_to_date(JND);
    temp=JND_to_date(JND);
    return temp;
}

/*
Меняет даты местами
*/
void swap(Date& lhs, Date& rhs)
{
    
	Date temp = lhs;
	lhs = rhs;
	rhs = temp;
}

/*
Меняет временные интервалы местами
*/
void swap(TimeDelta& lhs, TimeDelta& rhs)
{
    
	TimeDelta temp = lhs;
	lhs = rhs;
	rhs = temp;
}

/*
Возвращает ссылку на большую дату
*/
Date& max(Date& lhs, Date& rsh)
{
  return countJND(lhs).delta > countJND(rsh).delta? lhs : rsh;
}

/*
Возвращает указатель на меньшую дату
*/
Date& min(Date& lhs, Date& rsh)
{
  return countJND(lhs).delta < countJND(rsh).delta? lhs : rsh;
}

/*
Возвращает указатель на минимальную дату в переданном массиве дат
*/
Date& getMinDate(Date dates[], int size)
{
Date tempMax = dates[0];
	int index = 0;
	for (int i = 1; i < size; ++i)
	{
		if (dates[i] < tempMax)
		{
			tempMax = dates[i];
			index = i;
		}
	}
	return dates[index];
}
/*
Возвращает указатель на максимальную дату в переданном массиве дат
*/
Date& getMaxDate(Date dates[], int size)
{
Date tempMax = dates[0];
	int index = 0;
	for (int i = 1; i < size; ++i)
	{
		if (dates[i] > tempMax)
		{
			tempMax = dates[i];
			index = i;
		}
	}
	return dates[index];
}
/*
Сортирует массив дат по указанному критерию
*/
void sort(Date dates[], SortBy sortBy = SortBy::Date);


}
