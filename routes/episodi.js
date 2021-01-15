'use strict';

const dao = require('../models/episodio-dao.js');
const express = require('express');
const router = express.Router();


/* GET course (home) page */
router.get('/', function(req, res, next) {
  console.log(req);
  dao.getAllEpisodio()
  .then((episodio) => {
    res.render('episodio', {title: 'Episodio', episodio});
  });
});

module.exports = router;
