-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: May 14, 2018 at 08:30 PM
-- Server version: 5.5.55-0ubuntu0.14.04.1
-- PHP Version: 7.0.19-1+deb.sury.org~trusty+2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `TRABALHO_DB`
--

-- --------------------------------------------------------

--
-- Table structure for table `CAMERA`
--

CREATE TABLE IF NOT EXISTS `CAMERA` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `Marca` varchar(20) NOT NULL,
  `Modelo` varchar(20) DEFAULT NULL,
  `Peso` int(11) NOT NULL DEFAULT '0',
  `Sensor` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=23 ;

--
-- Dumping data for table `CAMERA`
--

INSERT INTO `CAMERA` (`Id`, `Marca`, `Modelo`, `Peso`, `Sensor`) VALUES
(1, 'Canon', 'T3i', 1300, 'APS-C'),
(15, 'Nikon', 'D7000', 130, 'Full-frame'),
(16, 'Canon', '7D', 1450, 'Full-frame'),
(18, 'Nikon', 'D3100', 130, 'APS-C'),
(19, 'Sony', 'A90', 370, 'APS-C'),
(22, 'Sony', 'Alpha A7', 890, 'ASP-C');

-- --------------------------------------------------------

--
-- Table structure for table `FLASH`
--

CREATE TABLE IF NOT EXISTS `FLASH` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `Marca` varchar(20) NOT NULL,
  `Modelo` varchar(20) DEFAULT NULL,
  `Peso` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `FLASH`
--

INSERT INTO `FLASH` (`Id`, `Marca`, `Modelo`, `Peso`) VALUES
(1, 'Canon', 'SpeedLite 300', 300),
(2, 'Nikon', '560 Speelite', 470),
(3, 'Sony', 'HVL-F20M', 450);

-- --------------------------------------------------------

--
-- Table structure for table `LENTE`
--

CREATE TABLE IF NOT EXISTS `LENTE` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `Marca` varchar(20) NOT NULL,
  `Modelo` varchar(20) NOT NULL,
  `Peso` int(11) NOT NULL DEFAULT '0',
  `Zoom` bit(1) NOT NULL DEFAULT b'1',
  `Zoom_min` int(10) NOT NULL DEFAULT '18',
  `Zoom_max` int(10) DEFAULT NULL,
  `Abertura` varchar(3) NOT NULL DEFAULT '5.6',
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=9 ;

--
-- Dumping data for table `LENTE`
--

INSERT INTO `LENTE` (`Id`, `Marca`, `Modelo`, `Peso`, `Zoom`, `Zoom_min`, `Zoom_max`, `Abertura`) VALUES
(1, 'Leica', '50mm f/1.8', 334, b'0', 50, NULL, '1.8'),
(2, 'Nikon', 'Nikkor AF', 280, b'1', 70, 300, '1.8'),
(3, 'Leica', '50mm f/1.8', 334, b'0', 50, NULL, '1.8'),
(4, 'Canon', 'Fish-Eye', 320, b'0', 20, NULL, '5.6'),
(6, 'Nikon', 'Nikkor AF', 280, b'1', 70, 300, '1.8'),
(7, 'Sony', 'SEL FE 28-70mm f/3.5', 370, b'1', 28, 70, '3.5'),
(8, 'Leica', 'Summilux-M 35mm f/1.', 320, b'0', 35, NULL, '1.4');

-- --------------------------------------------------------

--
-- Table structure for table `PRODUTO_PRECO`
--

CREATE TABLE IF NOT EXISTS `PRODUTO_PRECO` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `Fk_Produto` int(11) NOT NULL,
  `Tipo_Produto` varchar(10) NOT NULL,
  `Novo` bit(1) NOT NULL,
  `Preco` float NOT NULL,
  `Quantidade` int(10) NOT NULL,
  PRIMARY KEY (`Id`),
  KEY `Fk_Produto` (`Fk_Produto`),
  KEY `Fk_Produto_2` (`Fk_Produto`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=20 ;

--
-- Dumping data for table `PRODUTO_PRECO`
--

INSERT INTO `PRODUTO_PRECO` (`Id`, `Fk_Produto`, `Tipo_Produto`, `Novo`, `Preco`, `Quantidade`) VALUES
(1, 1, 'CAMERA', b'1', 312.44, 1),
(2, 16, 'CAMERA', b'0', 1355.56, 7),
(3, 15, 'CAMERA', b'1', 355.97, 3),
(4, 4, 'LENTE', b'1', 2550.78, 2),
(5, 1, 'FLASH', b'0', 129.99, 1),
(6, 1, 'TRIPE', b'0', 119.98, 2),
(7, 3, 'LENTE', b'0', 3000.02, 1),
(8, 2, 'TRIPE', b'1', 1400.87, 5),
(9, 2, 'TRIPE', b'1', 1398.87, 4),
(10, 18, 'CAMERA', b'1', 3000.01, 4),
(11, 19, 'CAMERA', b'0', 2398.54, 4),
(12, 1, 'LENTE', b'1', 3200.01, 2),
(13, 2, 'LENTE', b'0', 2398.54, 1),
(14, 6, 'LENTE', b'1', 3200.01, 2),
(15, 7, 'LENTE', b'0', 4200.01, 7),
(16, 8, 'LENTE', b'1', 1256.01, 6),
(17, 2, 'FLASH', b'1', 298.01, 2),
(18, 3, 'FLASH', b'1', 453.01, 2),
(19, 22, 'CAMERA', b'0', 799.98, 1);

-- --------------------------------------------------------

--
-- Table structure for table `TRIPE`
--

CREATE TABLE IF NOT EXISTS `TRIPE` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `Marca` varchar(20) NOT NULL,
  `Modelo` varchar(20) DEFAULT NULL,
  `Peso` int(11) NOT NULL DEFAULT '0',
  `Carga_max` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Dumping data for table `TRIPE`
--

INSERT INTO `TRIPE` (`Id`, `Marca`, `Modelo`, `Peso`, `Carga_max`) VALUES
(1, 'Manfrotto', 'SP20', 540, 1300),
(2, 'YUNTENG', 'VCT-190', 1300, 2500);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
