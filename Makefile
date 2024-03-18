quadratic_equation.o: clean
	gcc -c -Wall -Werror -Wextra src/quadratic_equation.c -o quadratic_equation.o
quadratic_equation.a: quadratic_equation.o
	ar rc quadratic_equation.a quadratic_equation.o
	ranlib quadratic_equation.a
check: clean
	gcc -Wall -Wextra -Werror -o test tests/quad_tests.c src/quadratic_equation.c --coverage -lcheck -lm -lpthread -lsubunit 
	 ./test
lcov_report:clean check
	lcov -t "lcov_report" -o lcov_report.info -c -d . 
	genhtml -o lcov_report lcov_report.info
clean:
	rm -rf test *.a *.o *.gcda *gcno
	rm -rf lcov_report lcov_report.info