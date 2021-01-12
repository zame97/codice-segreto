# codice-segreto
Repository che serve solo a salvare le mie cose.

## installare le dipendenze npm
```sh
$ npm install -g nodemon
$ npm init
$ npm install express
$ npm install sqlite3
$ npm install morgan
$ npm install passport
$ npm install moment
$ npm install bcrypt
$ npm install ejs 
$ npm install
```
Se bcrypt da problemi, eseguire:
```sh
$ apt-get install g++
$ sudo apt-get install -y build-essential python
$ npm install node-pre-gyp
$ npm install -g node-gyp
$ nvm use stable 
```
## eseguire il codice
```sh
$ nodemon www.js
```
Sul browser andare all'indirizzo localhost:3000

Se la porta 3000 da problemi:
```sh
$ npx kill-port 3000
