CXX ?= g++
CFLAGS = -std=c++11
SHVER = 2

all: svm.o integrated

lib: svm.o
	if [ "$(OS)" = "Darwin" ]; then \
		SHARED_LIB_FLAG="-dynamiclib -Wl,-install_name,libsvm.so.$(SHVER)"; \
	else \
		SHARED_LIB_FLAG="-shared -Wl,-soname,libsvm.so.$(SHVER)"; \
	fi; \
	$(CXX) $${SHARED_LIB_FLAG} svm.o -o libsvm.so.$(SHVER)



integrated: integrated.cpp
		$(CXX) $(CFLAGS) integrated.cpp svm.o -o integrated

svm.o: svm.cpp svm.h
	$(CXX) $(CFLAGS) -c svm.cpp

clean:
	rm integrated svm.o

clean_data:
	rm 	rad_d1 rad_d1.t hjpd_d1 hjpd_d1.t hod_d1 hod_d1.t \
		rad_d2 rad_d2.t hjpd_d2 hjpd_d2.t hod_d2 hod_d2.t \
		rad_d2.t.predict hjpd_d2.t.predict hod_d2.t.predict