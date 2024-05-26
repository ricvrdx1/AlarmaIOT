
snipper ->rnc(crear componente)

-dependencias
npx expo install expo-sharing
npm install o yarn install
react-native link react-native-gesture-handler -------------Error-----------
 yarn add react-native-gesture-handler 
 npm install react-native-gesture-handler
  yarn add react-native-status-bar-height  
  npm install react-native-safe-area-context 
  npm install @react-navigation/stack  
  npm install @react-navigation/native    

-ejecutar
npx expo start --https -------------Error-----------

-instalkar las dependencias para fire base y google signups
npx expo install firebase
npx expo install expo-auth-session expo-crypto expo-web-browser
npx expo install expo-application
npx expo install expo-dev-cliente
yarn add @react-native-async-storage/async-storage
npx expo customize metro.config.js

-instalar repo para produccion en EAS
npm install -g eas-cli
(comando para entarr en la cuenta)
eas account
eas whoami
eas build:configure
npm install firebase
120321981822-53cnj2enmi4ta4k6nh0culiv1gv0qf9m.apps.googleusercontent.com
25:29

-generar la huella
keytool -genkeypair -alias miAlias -keyalg RSA -keysize 2048 -validity 365 -keystore "D:\escuela y cursos\miAlmacen.jks" ---ERROR---

-para exportar 
keytool -exportcert -alias miAlias -file certificado.pem -keystore "D:\escuela y cursos\miAlmacen.jks" ---ERROR---

-importar el pem a un archivo
keytool -list -v -keystore "D:\escuela y cursos\miAlmacen.jks"
keytool -keystore path-to-debug-or-production-keystore -list -v
C:\Users\Admin\.android
keytool -exportcert -list -v -alias miAlias -keystore D:\escuela y cursos\miAlmacen.jks
-huella digital
ertificate fingerprints:
SHA1: 25:77:05:39:79:4B:92:9B:EC:80:30:C8:05:E8:EF:EC:26:5D:2C:65
SHA256: 9D:1F:2D:CC:1C:C1:AD:03:38:76:47:EE:FD:3F:31:DF:FD:4A:96:B7:F9:41:09:05:C7:92:F4:7D:AB:DC:27:0C
-lanzar produccion con expo
npx expo prebuild