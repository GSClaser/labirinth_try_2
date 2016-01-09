android create project -k com.labirynth2.game --target android-16 -n labirinth2 -p . -a labirinth2
# -a - им�? главного java файла и андроид приложени�?
#android update project --target andorid-16 -p .
#ant debug
#cd bin

#keytool -genkey -v -keystore mykey.keystore -alias mykey -keyalg RSA -keysize 2048 -validity 10000 -storepass spassword -keypass kpassword1

#jarsigner -verbose -sigalg SHA1withRSA -digestalg SHA1 -keystore mykey.keystore HelloSDL2Activity-debug-unaligned.apk mykey -storepass spassword -keypass kpassword1

#rm HelloSDL2Activity.apk

#zipalign -v 4 HelloSDL2Activity-debug-unaligned.apk HelloSDL2Activity.apk
