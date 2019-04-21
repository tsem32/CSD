-- phpMyAdmin SQL Dump
-- version 4.8.0.1
-- https://www.phpmyadmin.net/
--
-- Φιλοξενητής: 127.0.0.1
-- Χρόνος δημιουργίας: 22 Ιουν 2018 στις 12:10:14
-- Έκδοση διακομιστή: 10.1.32-MariaDB
-- Έκδοση PHP: 7.2.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Βάση δεδομένων: `hospital`
--

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `events`
--

CREATE TABLE `events` (
  `user_id` longtext COLLATE utf8_unicode_ci NOT NULL,
  `Content` longtext COLLATE utf8_unicode_ci NOT NULL,
  `Date` longtext COLLATE utf8_unicode_ci NOT NULL,
  `evID` text COLLATE utf8_unicode_ci NOT NULL,
  `pID` text COLLATE utf8_unicode_ci NOT NULL,
  `service` text COLLATE utf8_unicode_ci NOT NULL,
  `isSimple` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Άδειασμα δεδομένων του πίνακα `events`
--

INSERT INTO `events` (`user_id`, `Content`, `Date`, `evID`, `pID`, `service`, `isSimple`) VALUES
('user1', 'Απλο Γεγονός 1-x2sU', 'Wed, June 20,12:00 - 13:00', 'x2sU', 'noinfox2sU', 'Περιγραφή', 1),
('user1', 'Απλό Γεγονός 2-UDqK', 'Fri, June 29, 12:00 - 13:00', 'UDqK', 'noinfoUDqK', 'Περιγραφή', 1),
('user1', 'Απλό Γεγονός 3-boHp', 'Fri, June 22, 12:00 - 13:00', 'boHp', 'noinfoboHp', 'Περιγραφή', 1),
('user2', 'Γεώργιος Στρατής-MaRM-XoCc', 'Fri, June 29, 12:00 - 13:00', 'XoCc', 'MaRM', 'Λόγος Επίσκεψης 3', 0),
('user2', 'Αντρέας Αποστολάκης-q63f-yIjH', 'Fri, July 06,12:00 - 13:00', 'yIjH', 'q63f', 'Λόγος Επίσκεψης 4', 0),
('user2', 'Νικόλαος Κολιάτσος-GPOA-hXhT', 'Mon, May 28, 12:00 - 13:00', 'hXhT', 'GPOA', 'Λόγος Επίσκεψης 4', 0),
('user2', 'Μαρία Κουρμούλη-QhHv-zzVU', 'Wed, June 06, 12:00 - 13:00', 'zzVU', 'QhHv', 'Λόγος Επίσκεψης 5', 0),
('user2', 'Ιωάννης Διαμαντόπουλος-VSCG-D4Y1', 'Tue, June 19, 12:00 - 13:00', 'D4Y1', 'VSCG', 'Λόγος Επίσκεψης 6', 0),
('user1', 'Patient ID-Vr1L', 'Thu, June 14, 12:00 - 13:00', 'Vr1L', 'noinfoVr1L', 'Λόγος Επίσκεψης', 1),
('user1', 'Γεώργιος Στρατής-MaRM-GNZN', 'Sat, June 30, 12:00 - 13:00', 'GNZN', 'MaRM', 'Λόγος Επίσκεψης', 0),
('user2', 'Γεώργιος Στρατής-MaRM-FHGZ', 'Wed, June 06, 12:00 - 13:00', 'FHGZ', 'MaRM', 'Λόγος Επίσκεψης 7', 0);

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `history`
--

CREATE TABLE `history` (
  `pid` text COLLATE utf8_unicode_ci NOT NULL,
  `service` text COLLATE utf8_unicode_ci NOT NULL,
  `description` text COLLATE utf8_unicode_ci NOT NULL,
  `date` date NOT NULL,
  `medication` text COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Άδειασμα δεδομένων του πίνακα `history`
--

INSERT INTO `history` (`pid`, `service`, `description`, `date`, `medication`) VALUES
('MarM', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-08', 'Αγωγή'),
('MarM', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-07', 'Αγωγή'),
('MarM', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-06', 'Αγωγή'),
('MarM', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-05', 'Αγωγή'),
('MarM', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-04', 'Αγωγή'),
('MarM', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-03', 'Αγωγή'),
('MarM', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-02', 'Αγωγή'),
('MarM', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-01', 'Αγωγή'),
('MarM', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-10', 'Αγωγή'),
('MarM', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-11', 'Αγωγή'),
('MarM', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-09', 'Αγωγή'),
('QhHv', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-10', 'Αγωγή'),
('QhHv', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-11', 'Αγωγή'),
('QhHv', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-12', 'Αγωγή'),
('QhHv', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-13', 'Αγωγή'),
('QhHv', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-14', 'Αγωγή'),
('QhHv', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-15', 'Αγωγή'),
('QhHv', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-16', 'Αγωγή'),
('QhHv', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-17', 'Αγωγή'),
('QhHv', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-18', 'Αγωγή'),
('QhHv', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-19', 'Αγωγή'),
('QhHv', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-20', 'Αγωγή'),
('QhHv', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-09', 'Αγωγή'),
('q63f', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-10', 'Αγωγή'),
('q63f', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-11', 'Αγωγή'),
('q63f', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-12', 'Αγωγή'),
('q63f', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-13', 'Αγωγή'),
('q63f', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-14', 'Αγωγή'),
('q63f', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-15', 'Αγωγή'),
('q63f', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-16', 'Αγωγή'),
('q63f', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-17', 'Αγωγή'),
('q63f', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-18', 'Αγωγή'),
('q63f', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-19', 'Αγωγή'),
('q63f', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-20', 'Αγωγή'),
('q63f', 'Λόγος Επίσκεψης', 'Περιγραφή', '2018-05-09', 'Αγωγή'),
('QhHv', 'Λόγος Επίσκεψης', 'Μια περιγραφή', '2018-05-17', 'Augmentin'),
('MaRM', 'Λόγος Επίσκεψης', 'Μια περιγραφή', '2018-05-31', 'Augmentin'),
('MaRM', 'Λόγος Επίσκεψης', 'Σχολια Νοσηλευτή/περιγραφή', '2018-06-13', 'Πιθανή αγωγή '),
('MaRM', 'Λόγος Επίσκεψης 2', 'Μια περιγραφή', '2018-06-28', 'Augmentin'),
('MaRM', 'Λόγος Επίσκεψης 1', '', '2018-06-22', '');

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `patients`
--

CREATE TABLE `patients` (
  `pid` mediumtext COLLATE utf8_unicode_ci NOT NULL,
  `FullName` mediumtext COLLATE utf8_unicode_ci NOT NULL,
  `Details` mediumtext COLLATE utf8_unicode_ci NOT NULL,
  `bday` text COLLATE utf8_unicode_ci NOT NULL,
  `phone` mediumtext COLLATE utf8_unicode_ci NOT NULL,
  `Address` mediumtext COLLATE utf8_unicode_ci NOT NULL,
  `fathersName` text COLLATE utf8_unicode_ci NOT NULL,
  `mothersName` text COLLATE utf8_unicode_ci NOT NULL,
  `gender` text COLLATE utf8_unicode_ci NOT NULL,
  `marState` text COLLATE utf8_unicode_ci NOT NULL,
  `Insurance` text COLLATE utf8_unicode_ci NOT NULL,
  `amka` text COLLATE utf8_unicode_ci NOT NULL,
  `ama` text COLLATE utf8_unicode_ci NOT NULL,
  `relPhone` text COLLATE utf8_unicode_ci NOT NULL,
  `job` text COLLATE utf8_unicode_ci NOT NULL,
  `FullNameEn` text COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Άδειασμα δεδομένων του πίνακα `patients`
--

INSERT INTO `patients` (`pid`, `FullName`, `Details`, `bday`, `phone`, `Address`, `fathersName`, `mothersName`, `gender`, `marState`, `Insurance`, `amka`, `ama`, `relPhone`, `job`, `FullNameEn`) VALUES
('MaRM', 'Γεώργιος Στρατής', 'Σχολια γιατρού/λεπτομέριες', '03/29/2000', '2810 347265', 'Χουλογιάννη 3', 'Αντρέα', 'Αντρή', 'Άντρας', 'Έγγαμος', 'ΟΓΑ', '2019243994', '8438333140', '6926047771', 'Ανεργος', 'Georgios Stratis'),
('18x5', 'Νικόδημος Πρωτοπαπάς ', 'Σχολια γιατρού/λεπτομέριες', '6/13/1969', '2813 456982', 'Καλοκαιρινού 124', 'Ιωάννης', 'Νίκη', 'Άντρας', 'Άγαμος', 'ΟΓΑ', '287426343', '1330947800', '6956051359', 'Δημόσιος Υπάλληλος', 'Nikodimos Prwtopapas'),
('pIzg', 'Στεφανη Κιλε  ', 'Σχολια γιατρού/λεπτομέριες', '03/18/1958', '6985412369', 'Γεωργιάδη Τίτου 23', 'Νικόλαος', 'Κατερίνα', 'Γυναίκα', 'Άγαμος', 'ΟΑΕΕ', '369889411', '7399239355', '6903736583', 'Ελεύθερος Επαγγελματίας', 'Stefani Kile'),
('OfTw', 'Γεώργιος Ασλανίδης', 'Σχολια γιατρού/λεπτομέριες', '1/24/1978\r\n', '2810 814482', 'Κισσάμου 4', 'Αριστοτέλης', 'Μαρία', 'Άντρας', 'Έγγαμος', 'ΟΓΑ', '2511781868', '6136850867', '6997269976', 'Δημόσιος Υπάλληλος', 'Georgios Aslanidis'),
('Zio6', 'Γεώργιος Βαρνακιώτης', 'Σχολια γιατρού/λεπτομέριες', '11/27/1981', '2810 088025', 'Σαββαθιανών 7', 'Παντελής', 'Ερατώ', 'Άντρας', 'Άγαμος', 'ΟΑΕΕ', '7021036738', '1543019978', '6990508720', 'Δημόσιος Υπάλληλος', 'Georgios Varnakiotis'),
('GPOA', 'Νικόλαος Κολιάτσος', 'Σχολια γιατρού/λεπτομέριες', '2/14/1986', '2810 857514', 'Αρχιεπισκόπου 43', 'Ιωάννης', 'Ευριδίκη', 'Άντρας', 'Έγγαμος', 'ΟΓΑ', '5400053468', '0991461256', '6960995008', 'Σερβιτόρος', 'Nikolas Koliatsos'),
('QhHv', 'Μαρία Κουρμούλη', 'Σχολια γιατρού/λεπτομέριες', '9/20/1955', '2810 397389', 'Αλκαίου 23', 'Κωσταντίνος', 'Παντελία', 'Γυναίκα', 'Άγαμος', 'IKA', '9117148583', '2298428931', '6957236165', 'Ελεύθερος Επαγγελματίας', 'Maria Kourmouli'),
('4jIJ', 'Μαρία Κουρτίδη', 'Σχολια γιατρού/λεπτομέριες', '7/31/1968', '2810 147038', 'Πετλεμπούρη 76', 'Θεόδωρος', 'Νικολίνα', 'Γυναίκα', 'Έγγαμος', 'ΟΓΑ', '9529106659', '1479330049', '6958510341', 'Ελεύθερος Επαγγελματίας', 'Maria Kourtidi'),
('Uots', 'Κατερίνα Κεχαγιά', 'Σχολια γιατρού/λεπτομέριες', '12/6/1982', '2810 750861', 'Γορτύνης 23', 'Πολύκαρπος', 'Μαρια', 'Γυναίκα', 'Έγγαμος', 'IKA', '5523453168', '3264583463', '6977326521', 'Ιδιωτικός Υπάλληλος', 'Katerina Kexagia'),
('VSCG', 'Ιωάννης Διαμαντόπουλος', 'Σχολια γιατρού/λεπτομέριες', '2/4/1983', '2810 169586', 'Συβρίτου 22', 'Κωσταντίνος', 'Στυλιανή', 'Άντρας', 'Άγαμος', 'ΟΑΕΕ', '4267360942', '7650735084', '6922985169', 'Ιδιωτικός Υπάλληλος', 'Ioannis Diamantopoulos'),
('q63f', 'Αντρέας Αποστολάκης', 'Σχολια γιατρού/λεπτομέριες', '7/12/1960', '2810 938292', 'Σκουλάδων 23', 'Γεώργιος', 'Ελένη', 'Άντρας', 'Άγαμος', 'IKA', '1388407531', '2212323283', '6949520129', 'Δημόσιος Υπάλληλος', 'Antreas Apostolakis'),
('r6y1', 'test ', 'asdfsadfsdf', '08/25/1997', 'asdf', 'asdf', 'asdf', 'asdf', 'Άντρας', 'Έγγαμος', 'ΙΚΑ', 'asdf', 'asdf', 'asdf', 'asdf', 'test');

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `staff`
--

CREATE TABLE `staff` (
  `ama` int(10) NOT NULL,
  `hasActive` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Άδειασμα δεδομένων του πίνακα `staff`
--

INSERT INTO `staff` (`ama`, `hasActive`) VALUES
(45062692, 0),
(414365038, 0),
(985238348, 0),
(2079682204, 0),
(129504775, 0),
(2125643515, 0),
(605679058, 0),
(975271465, 0),
(648735974, 0),
(1809140580, 0),
(401571213, 0),
(674325377, 0),
(226455299, 0),
(130822093, 0),
(64494423, 0),
(38942487, 0),
(138957223, 0),
(327116457, 0),
(953400041, 0),
(845220020, 0),
(637212680, 0),
(292045583, 0),
(164153191, 0),
(936582363, 0),
(812781465, 0),
(718798673, 0),
(468190839, 0),
(627865189, 0),
(272383867, 0),
(935952766, 0),
(849926529, 0),
(767918609, 0),
(644463679, 0),
(834991510, 0),
(781733123, 0),
(505740034, 0),
(760446004, 0),
(1234567894, 0),
(1234567893, 0),
(1234567892, 0),
(1234567891, 0),
(1234567890, 1);

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `users`
--

CREATE TABLE `users` (
  `Username` mediumtext COLLATE utf8_unicode_ci NOT NULL,
  `Password` mediumtext COLLATE utf8_unicode_ci NOT NULL,
  `Name` mediumtext COLLATE utf8_unicode_ci,
  `Lastname` mediumtext COLLATE utf8_unicode_ci NOT NULL,
  `isAdmin` tinyint(1) NOT NULL,
  `email` text COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Άδειασμα δεδομένων του πίνακα `users`
--

INSERT INTO `users` (`Username`, `Password`, `Name`, `Lastname`, `isAdmin`, `email`) VALUES
('admin', '21232f297a57a5a743894a0e4a801fc3', 'Αναστάσιος', 'Γιαλαμούδης', 1, 'gialamoud@csd.uoc.gr'),
('user1', '51751119445e108bf63c028087625421', 'Αναστάσιος', 'Γιαλαμούδης', 0, 'gialamoud@csd.uoc.gr'),
('user2', '51751119445e108bf63c028087625421', 'Αναστάσιος', 'Γιαλαμούδης', 0, 'gialamoud@csd.uoc.gr'),
('user3', '51751119445e108bf63c028087625421', 'Αναστάσιος', 'Γιαλαμούδης', 0, 'gialamoud@csd.uoc.gr'),
('user4', '51751119445e108bf63c028087625421', 'Αναστάσιος', 'Γιαλαμούδης', 0, 'gialamoud@csd.uoc.gr');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
