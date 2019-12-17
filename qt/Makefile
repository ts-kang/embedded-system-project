obj-y += devices/

obj-y += main.o
obj-y += mainwindow.o
obj-y += moc_mainwindow.o

$(obj)/moc_mainwindow.cpp: $(obj)/mainwindow.h \
		/usr/lib/arm-linux-gnueabihf/qt5/bin/moc
	/usr/lib/arm-linux-gnueabihf/qt5/bin/moc $(DEFINES) -I/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/linux-g++ -I/home/pi/testQt/qt_fpga_step_motor -I/usr/include/arm-linux-gnueabihf/qt5 -I/usr/include/arm-linux-gnueabihf/qt5/QtWidgets -I/usr/include/arm-linux-gnueabihf/qt5/QtGui -I/usr/include/arm-linux-gnueabihf/qt5/QtCore -I. -I/usr/include/c++/6 -I/usr/include/arm-linux-gnueabihf/c++/6 -I/usr/include/c++/6/backward -I/usr/lib/gcc/arm-linux-gnueabihf/6/include -I/usr/local/include -I/usr/lib/gcc/arm-linux-gnueabihf/6/include-fixed -I/usr/include/arm-linux-gnueabihf -I/usr/include $(obj)/mainwindow.h -o $(obj)/moc_mainwindow.cpp

$(obj)/ui_mainwindow.h: $(obj)/mainwindow.ui \
		/usr/lib/arm-linux-gnueabihf/qt5/bin/uic
	/usr/lib/arm-linux-gnueabihf/qt5/bin/uic $(obj)/mainwindow.ui -o $(obj)/ui_mainwindow.h

$(obj)/mainwindow.o: $(obj)/ui_mainwindow.h
