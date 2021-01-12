'use strict'

const { router } = require('../app');
const db = require('../db/js');

exports.putPersonalInfo = function() {
    return new Promise((resolve, reject) => {
        const sql = 'INSERT INTO utente(email, password, nome,admin) VALUES (?, ?, ?, ?)';
        var params = [email, password, nome, admin];
        db.run(sql, params, (err, rows) => {
            if(err) {
                reject(err);
                return;
            }
            resolve();
        });
    });
}; 