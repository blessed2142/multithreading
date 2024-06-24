cmake_minimum_required(VERSION 2.8)	 # Проверка версии CMake.
										# Если версия установленой программы
										# старее указаной, произайдёт аварийный выход.

project(test)			# Название проекта

set(SOURCE_EXE test/test.cpp)		# Установка переменной со списком исходников для исполняемого файла

set(SOURCE_LIB test/foo.cpp)			# Тоже самое, но для библиотеки

add_library(foo STATIC ${SOURCE_LIB})	# Создание статической библиотеки с именем foo

add_compile_options( -g )

add_executable(test ${SOURCE_EXE})	# Создает исполняемый файл с именем test

target_link_libraries(test foo pthread )		# Линковка программы с библиотекой