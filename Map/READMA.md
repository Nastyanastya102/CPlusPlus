## Задание

Написать шаблонный класс Map, представляющий из себя ассоциативный контейнер (словарь). Класс содержит два односвязных (связанных логикой и одинакового размера) динамических массива (ключ и значение), возможно, двух разных типов данных.
* Создавать словарь пустым.
* insert(key, value). Добавляет элементы, перевыделяя
динамическую память. Элементы добавляются как ключ/
значение в два соответствующих массива.
* remove(key). Удаляет элементы по переданному ключу.
* count(key). Подсчитывает количество элементов с таким
ключом.
* empty(). Проверка, не пустой ли словарь.
* length(). Количество элементов словаря.
* Перегрузить оператор вывода <<.
* Перегрузить оператор [], который будет возвращать либо
изменять значение по переданному ключу.