cmake_minimum_required(VERSION 2.8)	 # �������� ������ CMake.
										# ���� ������ ������������ ���������
										# ������ ��������, ��������� ��������� �����.

project(test)			# �������� �������

set(SOURCE_EXE test/test.cpp)		# ��������� ���������� �� ������� ���������� ��� ������������ �����

set(SOURCE_LIB test/foo.cpp)			# ���� �����, �� ��� ����������

add_library(foo STATIC ${SOURCE_LIB})	# �������� ����������� ���������� � ������ foo

add_compile_options( -g )

add_executable(test ${SOURCE_EXE})	# ������� ����������� ���� � ������ test

target_link_libraries(test foo pthread )		# �������� ��������� � �����������