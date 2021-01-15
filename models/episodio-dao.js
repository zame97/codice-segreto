'use strict';

const db = require('../db.js');

exports.getAllEpisodio = function() {
  return new Promise((resolve, reject) => {
    const sql = 'SELECT * FROM episodio  WHERE id_serie = ?';
    db.all(sql, (err, rows) => {
      if (err) {
        reject(err);
        return;
      }
      
      const episodio = rows.map((e) => ({id: e.id_episodio, audio: e.audio, titolo: e.titolo_episodio, 
        descrizione: e.descrizione_episodio, data: e.data, sponsor: e.sponsor, 
        costo: e.costo, serie: e.id_serie}));
      resolve(episodio);
    });
  });
};
