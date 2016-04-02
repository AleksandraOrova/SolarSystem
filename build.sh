#!/bin/bash

export PATH=$PATH:/opt/Qt5.5.0/5.5/gcc_64/bin/

build_release_version() {
	cd sources/Pro_Solar_System
	qmake --version
	qmake
	if [ -e "Makefile" ]; then
		make --version
		make
		cd ../..
	else
		echo "Makefile does not exist"
		echo "Build release version failure!"
		exit 1
	fi	
}

build_debug_version() {
	cd sources/Pro_Solar_System
	cloc --version
	cloc --by-file --xml --out=../../report/clock
	qmake --version
	qmake "QMAKE_CXXFLAGS+=-fprofile-arcs -ftest-coverage -fPIC -O0 -g --coverage" "LIBS+=-lgcov"
	if [ -e "Makefile" ]; then
		make --version
		make
		#Test/tst_testcore -xml -o test_results || true
		cppcheck --version
		cppcheck --enable=all -v  --xml  * 2> ../../report/cppcheck_result
		gcovr --version
		gcovr -r . --xml --exclude='tst*' -o ../../report/gcovr_result
		
		valgrind --version
		valgrind --leak-check=full --xml=yes --xml-file=/opt/tomcat/.jenkins/jobs/FootballEditor16/workspace/tst_testcore.%p.result /opt/tomcat/.jenkins/jobs/FootballEditor16/workspace/sources/FootballEditor16/Test/tst_testcore || true

		cd ../..
	else
		echo "Makefile does not exist"
		echo "Build debug version failure!"
		exit 1
	fi
}

make_report() {
	cd report
	if [ -e "doxygen.ini" ]; then
			doxygen --version
			doxygen doxygen.ini
		else
			echo "Doxygen failed"
			echo "doxygen.ini does not exist"
		fi
	cd sources/FootballEditor16/doxygen/latex
	if [ -e "Makefile" ]; then
		make --version
		make
#		cd ../../../../report
#		pdflatex FootballEditor16.tex
#		pdflatex FootballEditor16.tex
#		pdflatex FootballEditor16.tex
#		cd ..
		cd ../../../..
	else
		echo "Makefile does not exist"
		echo "Report failure!"
		cd ../..
		exit 1
	fi
}

zip_files() {
	if [ -z ${JOB_NAME} ] || [ -z ${BUILD_NUMBER}]; then
		echo "Vars JOB_NAME/BUILD_NUMBER are unset"
		echo "Zip failure!"
		exit 1
	fi

	TITLE="${JOB_NAME}_v${BUILD_NUMBER}"
	mkdir "$TITLE"

	if [ -e "sources/FootballEditor16/ConsoleApp/ConsoleApp" ]; then
		cp sources/FootballEditor16/ConsoleApp/ConsoleApp $TITLE/FootballEditor16_v${BUILD_NUMBER}
		if [ -e "report/FootballEditor16.pdf" ]; then
			cp report/FootballEditor16.pdf $TITLE/FootballEditor16_v${BUILD_NUMBER}.pdf
		fi
		if [ -e "sources/FootballEditor16/doxygen/latex/refman.pdf" ]; then
			cp sources/FootballEditor16/doxygen/latex/refman.pdf $TITLE/FootballEditor16Doxygen_v${BUILD_NUMBER}.pdf
		fi
		zip --version
		zip $TITLE.zip $TITLE/*
	else
		echo "ConsoleApp does not exist"
		echo "Zip failure!"
		exit 1
	fi

}

clean() {
	git clean -f -e *.zip *.pdf
}
