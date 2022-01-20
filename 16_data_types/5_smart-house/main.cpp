#include <iostream>
#include <string>
#include <sstream>

enum switches {
    MAIN             = 1 << 0,
    MAIN_SOCKETS     = 1 << 1,
    INDOOR_LIGHT     = 1 << 2,
    OUTDOOR_LIGHT    = 1 << 3,
    INDOOR_HEATING   = 1 << 4,
    PLUMBING_HEATING = 1 << 5,
    AIR_CONDITIONER  = 1 << 6
};

const int HOURS_SIMULATION = 48,
          HOURS_IN_A_DAY = 24,
          START_NIGHT_TIME = 16,
          END_NIGHT_TIME = 20,
          MAX_TEMPERATURE_COLOR = 5000,
          MIN_TEMPERATURE_COLOR = 2700;


std::string BoolToString (const bool& value) {
    if (value) {
        return "yes";
    }
    else {
        return "no";
    }
}

void CheckIndoorLight (int& state, const bool& indoorMovement, const int& hours) {
    bool nightTime = hours >= 16 && hours <= 20;

    if ( !nightTime && state & INDOOR_LIGHT) {
        state &= ~INDOOR_LIGHT;
        std::cout << "Switch indoor Light: off" << std::endl;
    }
    else if (nightTime && indoorMovement && ~state & INDOOR_LIGHT) {
        state |= INDOOR_LIGHT;
        std::cout << "Switch indoor Light: on" << std::endl;
    }
    else if ( !indoorMovement && state & INDOOR_LIGHT) {
        state &= ~INDOOR_LIGHT;
        std::cout << "Switch indoor Light: off" << std::endl;
    }
}

void CheckTemperatureColor (int& temperature, const int& state,  const bool& indoorMovement, const int& hours) {
    int delta = int((MAX_TEMPERATURE_COLOR - MIN_TEMPERATURE_COLOR) / (END_NIGHT_TIME - START_NIGHT_TIME));
    bool nightTime = hours >= START_NIGHT_TIME && hours <= END_NIGHT_TIME;

    if (hours == 0) {
        temperature = MAX_TEMPERATURE_COLOR;
    }
    else if (nightTime && indoorMovement && ~state & INDOOR_LIGHT) {
        temperature = MAX_TEMPERATURE_COLOR - delta * (hours - START_NIGHT_TIME);
        std::cout << "Color temperature: " << temperature << std::endl;
    }
    else if (nightTime && indoorMovement && state & INDOOR_LIGHT) {
        temperature -= delta;
        std::cout << "Color temperature: " << temperature << std::endl;
    }
}

void CheckOutsideLight (int& state, const bool& outdoorMovement, const int& hours) {
    bool daylightHours = hours >= 5 && hours < 16;

    if (daylightHours && state & OUTDOOR_LIGHT) {
        state &= ~OUTDOOR_LIGHT;
        std::cout << "Switch outside Light: off" << std::endl;
    }
    else if ( !daylightHours && outdoorMovement && ~state & OUTDOOR_LIGHT) {
        state |= OUTDOOR_LIGHT;
        std::cout << "Switch outside Light: on" << std::endl;
    }
    else if ( !outdoorMovement && state & OUTDOOR_LIGHT) {
        state &= ~OUTDOOR_LIGHT;
        std::cout << "Switch outside Light: off" << std::endl;
    }
}

void CheckIndoorHating (int& state, const double& temperature) {
    if (temperature < 22 && ~state & INDOOR_HEATING) {
        state |= INDOOR_HEATING;
        std::cout << "Switch indoor heating: on" << std::endl;
    }
    else if (temperature >= 25 && state & INDOOR_HEATING) {
        state &= ~INDOOR_HEATING;
        std::cout << "Switch indoor heating: off" << std::endl;
    }
    else if (temperature >= 30 && ~state & AIR_CONDITIONER) {
        state |= AIR_CONDITIONER;
        std::cout << "Switch air conditioner: on" << std::endl;
    }
    else if (temperature < 25 && state & AIR_CONDITIONER) {
        state &= ~AIR_CONDITIONER;
        std::cout << "Switch air conditioner: off" << std::endl;
    }
}

void CheckPlumbingHating (int& state, const double& temperature) {
    if (temperature < 0 && ~state & PLUMBING_HEATING) {
        state |= PLUMBING_HEATING;
        std::cout << "Switch plumbing heating: on" << std::endl;
    }
    else if (temperature > 5 && state & PLUMBING_HEATING) {
        state &= ~PLUMBING_HEATING;
        std::cout << "Switch plumbing heating: off" << std::endl;
    }
}

int main() {
    std::stringstream text;

    int switchState = 0,
        colorTemperature;

    bool indoorLightSensor = false,
         outsideLightSensor = false;

    double indoorTemperatureSensor = 0.0,
           outsideTemperatureSensor = 0.0;

    std::cout << "Input example: 1 0 23.1 15.2" << std::endl;
    std::cout << "Indoor movement, outside movement, indoor temperature, outside temperature." << std::endl;

    for (int hours = 16; hours < HOURS_SIMULATION; hours++) {
        std::string input;

        std::cout << "The current time is " << hours % HOURS_IN_A_DAY << ":00 hours, enter the state of the sensors:" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cin >> input;
            text << input << " ";
        }
        text >> indoorLightSensor >> outsideLightSensor >> indoorTemperatureSensor >> outsideTemperatureSensor;

        std::cout << std::endl;
        std::cout << "Indoor movement:     " << BoolToString( indoorLightSensor) << std::endl;
        std::cout << "Outside movement:    " << BoolToString( outsideLightSensor) << std::endl;
        std::cout << "Indoor temperature:  " << indoorTemperatureSensor << std::endl;
        std::cout << "Outside temperature: " << outsideTemperatureSensor << std::endl;

        CheckTemperatureColor(colorTemperature, switchState, indoorLightSensor, hours % HOURS_IN_A_DAY);

        std::cout << std::endl;
        CheckIndoorLight( switchState, indoorLightSensor, hours % HOURS_IN_A_DAY);
        CheckOutsideLight( switchState, outsideLightSensor, hours % HOURS_IN_A_DAY);
        CheckIndoorHating( switchState, indoorTemperatureSensor);
        CheckPlumbingHating( switchState, outsideTemperatureSensor);
        std::cout << "-------------------------------------------------------------------------------------"<< std::endl;
    }
    return 0;
}

/*
 *  Умный дом

    Что нужно сделать

    Надо разработать упрощённую модель умного дома для дачи. Есть несколько датчиков: датчик температуры снаружи, датчик
температуры внутри дома. В доме расположен электронный “умный” щиток с автоматами. Каждый автомат отвечает за включение
и отключение определённых устройств или групп устройств. Первый автомат - это отключение и включение питания всего дома,
второй - основные розетки дома, третий - свет внутри дома, четвёртый - наружный свет в саду, пятый - отопление в помещении,
шестой - отопление водопровода идущего из скважины с насосом, седьмой - кондиционер в помещении.

    Есть несколько условий по включению/отключению техники в доме и вне его.

    Как только температура снаружи падает ниже 0, надо включить систему обогрева водопровода и отключить её, если
температура снаружи поднялась выше 5 градусов.

    Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение, то необходимо включить
садовое освещение. Если движения нет или время не вечернее - света снаружи быть не должно.

    При условии, что температура в помещении упала ниже 22 градусов, должно включится отопление. Как только температура
поднимается выше или равно 25-и градусам, отопление автоматически отключается.

    Если температура в помещении поднялась до 30 градусов, включается кондиционер. Как только температура становится 25
градусов - кондиционер отключается.

    Всё освещение в доме также “умное” и поддерживает настройку цветовой температуры для комфортного нахождения. Каждый
день начиная с 16:00 и до 20:00, температура цвета должна плавно изменяться с 5000K до 2700К. Разумеется, это изменение
должно происходить в случае, если свет сейчас включен. В 0:00 температура сбрасывается до 5000К.

    Все события по отключению и включению устройств должны выводится в консоль явным образом. Если устройство не изменило
своего состояния (осталось включенным или выключенным) события генерироваться не должно! Если свет в доме включен, должна
отображаться текущая цветовая температура.

    Программа выполняется следующим образом. Каждый час пользователь сообщает состояние всех основных датчиков и света:
температура снаружи, температура внутри, есть ли движение снаружи, включен ли свет в доме. Данные параметры вводятся
разом в одну строку, через пробел, а потом парсятся в переменные из строкового буфера stringstream. Информация о движении
выводится в формате yes/no. Включение и отключение света происходит с помощью on/off. Стартовое время для симуляции
умного дома - это 0:00. Требуется осуществить симуляцию на протяжении двух дней.
 */