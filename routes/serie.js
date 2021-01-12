'use strict';

const dao = require('../models/serie-dao.js');
const express = require('express');
const router = express.Router();


/* GET course (home) page */
router.get('/', function(req, res, next) {
  console.log(req);
  dao.getAllSerie()
  .then((serie) => {
    res.render('serie', {title: 'Serie', serie});
  });
});

module.exports = router;

//usare questo file anche per un file episodi.js