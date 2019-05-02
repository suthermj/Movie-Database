-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: May 01, 2019 at 07:44 PM
-- Server version: 5.6.41-84.1
-- PHP Version: 7.2.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `fivpeopl_movie`
--

-- --------------------------------------------------------

--
-- Table structure for table `Comments`
--

CREATE TABLE `Comments` (
  `movieID` int(11) NOT NULL,
  `comment` varchar(600) COLLATE utf8_unicode_ci NOT NULL,
  `user` varchar(200) COLLATE utf8_unicode_ci NOT NULL,
  `date` datetime NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `Comments`
--

INSERT INTO `Comments` (`movieID`, `comment`, `user`, `date`) VALUES
(0, '', '', '0000-00-00 00:00:00'),
(1, 'This was a great movie!', 'shrimply pibbles', '2019-04-25 17:31:00');

-- --------------------------------------------------------

--
-- Table structure for table `tblMovies`
--

CREATE TABLE `tblMovies` (
  `id` int(20) NOT NULL,
  `title` varchar(200) COLLATE utf8_unicode_ci NOT NULL,
  `genre` varchar(300) COLLATE utf8_unicode_ci NOT NULL,
  `director` varchar(200) COLLATE utf8_unicode_ci NOT NULL,
  `year` varchar(200) COLLATE utf8_unicode_ci NOT NULL,
  `image` varchar(600) COLLATE utf8_unicode_ci NOT NULL DEFAULT 'https://s.studiobinder.com/wp-content/uploads/2017/12/Movie-Poster-Template-Dark-with-Image.jpg?x81279&resolution=2560,2',
  `description` varchar(400) COLLATE utf8_unicode_ci NOT NULL DEFAULT 'Description',
  `isDelete` tinyint(1) NOT NULL DEFAULT '0',
  `isPending` tinyint(1) NOT NULL DEFAULT '1'
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `tblMovies`
--

INSERT INTO `tblMovies` (`id`, `title`, `genre`, `director`, `year`, `image`, `description`, `isDelete`, `isPending`) VALUES
(1, 'The Dark Knight', 'Action/Crime/Drama', 'Christopher Nolan', '2008', 'https://www.joblo.com/assets/images/oldsite/posters/images/full/2008-dark_knight-5.jpg', 'When the menace known as The Joker emerges from his mysterious past, he wreaks havoc and chaos on the people of Gotham. The Dark Knight must accept one of the greatest psychological and physical tests of his ability to fight injustice.', 0, 0),
(2, 'Toy Story 4', 'Animation/Adventure/Comedy', 'Josh Cooley', '2019', 'https://www.joblo.com/assets/images/joblo/posters/2019/04/toy_story_four_ver11_xlg.jpg', 'Description', 0, 0),
(3, 'Forrest Gump', 'Drama', 'R.L Stine', '1990', 'http://www.gstatic.com/tv/thumb/v22vodart/15829/p15829_v_v8_ab.jpg', 'A funny man goes on an adventure', 0, 0),
(4, 'The White Crow', 'Biography | Drama', 'Ralph Fiennes', '2018', 'https://m.media-amazon.com/images/M/MV5BNGIwMjFmMGQtZjYxNC00NmJjLTlkM2QtMWMyZTA3YjZhNzBlXkEyXkFqcGdeQXVyOTgxNDIzMTY@._V1_UY209_CR0,0,140,209_AL_.jpg', 'The story of Rudolf Nureyev\'s defection to the West.', 0, 0),
(5, 'The Godfather', 'Crime, Drama', ' Francis Ford Coppola', '1972', 'https://m.media-amazon.com/images/M/MV5BM2MyNjYxNmUtYTAwNi00MTYxLWJmNWYtYzZlODY3ZTk3OTFlXkEyXkFqcGdeQXVyNzkwMjQ5NzM@._V1_UY268_CR3,0,182,268_AL_.jpg', 'The aging patriarch of an organized crime dynasty transfers control of his clandestine empire to his reluctant son.', 0, 0),
(19, 'Breakthrough', 'Drama', 'Roxann Dawson', '2019', 'https://www.joblo.com/assets/images/joblo/posters/2019/03/breakthrough.jpg', 'BREAKTHROUGH is based on the inspirational true story of one mother’s unfaltering love in the face of impossible odds. When Joyce Smith’s adopted son John falls through an icy Missouri lake, all hope seems lost. ', 0, 0),
(31, '', '', '', '', '', '', 0, 0),
(32, '', '', '', '', '', '', 0, 0),
(25, 'Schindlers List', ' Biography, Drama, History ', 'Steven Spielberg', '1993', 'https://www.joblo.com/assets/images/oldsite/posters/images/full/1993-schindlers-list-poster1.jpg', 'In German-occupied Poland during World War II, industrialist Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis.', 0, 0),
(26, 'Saving Private Ryan', 'Drama, War', 'Steven Spielberg', '1998', 'https://www.joblo.com/assets/images/oldsite/posters/images/full/1998-poster-saving_private_ryan-2.jpg', 'Following the Normandy Landings, a group of U.S. soldiers go behind enemy lines to retrieve a paratrooper whose brothers have been killed in action.', 0, 0),
(27, 'Fantastic Four', 'Action, Adventure, Drama ', 'Josh Trank', '2015', 'https://www.joblo.com/assets/images/oldsite/posters/images/full/Fantastic-Four-Poster-3.jpg', 'Transported to an alternate universe, four young outsiders gain superhuman powers as they alter their physical form in shocking ways. Reed Richards becomes Mr. Fantastic, able to stretch and twist his body at will, while pal Ben Grimm gains immense strength as the Thing. Johnny Storm becomes the Human Torch, able to control and project fire, while his sister Sue becomes the Invisible Woman. Togeth', 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `tblUsers`
--

CREATE TABLE `tblUsers` (
  `id` int(11) NOT NULL,
  `username` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `email` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `password` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `trn_date` datetime NOT NULL,
  `permission` int(10) NOT NULL DEFAULT '1'
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `tblUsers`
--

INSERT INTO `tblUsers` (`id`, `username`, `email`, `password`, `trn_date`, `permission`) VALUES
(1, 'budowja', 'budowja@miamioh.edu', '835b68366a71050642ad1128c06c9cb1', '2019-04-22 17:39:05', 3),
(4, 'dangeraa', 'dangeraa@miamioh.edu', '01e97695d22d713320f90d9b970c45c2', '2019-04-22 22:45:28', 3),
(5, '1', '1', 'c4ca4238a0b923820dcc509a6f75849b', '2019-04-23 06:35:03', 1),
(6, 'test', 'test@gmail.com', '098f6bcd4621d373cade4e832627b4f6', '2019-04-23 13:21:45', 1),
(12, 'lucku', 'akjdf@lkad.com', 'eab42973d676d4de4bd8b9ceb2636b7b', '2019-04-24 02:43:34', 1),
(10, 'suthermj', 'suthermj@miamioh.edu', '5f4dcc3b5aa765d61d8327deb882cf99', '2019-04-24 02:35:32', 3),
(13, 'testing2', '1@2.com', '5f4dcc3b5aa765d61d8327deb882cf99', '2019-04-24 03:25:19', 1),
(14, '1', '1', 'c4ca4238a0b923820dcc509a6f75849b', '2019-04-24 06:33:23', 1),
(15, '1', '1', 'c4ca4238a0b923820dcc509a6f75849b', '2019-04-25 06:36:51', 1),
(16, 'syddog', 'syd@dick.com', '5d41402abc4b2a76b9719d911017c592', '2019-04-25 22:46:06', 1),
(17, '1', '1', 'c4ca4238a0b923820dcc509a6f75849b', '2019-04-26 06:39:02', 1),
(18, '1', '1', 'c4ca4238a0b923820dcc509a6f75849b', '2019-04-27 06:40:24', 1),
(19, '1', '1', 'c4ca4238a0b923820dcc509a6f75849b', '2019-04-28 06:41:54', 1),
(20, '1', '1', 'c4ca4238a0b923820dcc509a6f75849b', '2019-04-29 06:35:59', 1),
(21, '1', '1', 'c4ca4238a0b923820dcc509a6f75849b', '2019-04-30 06:36:56', 1),
(22, '1', '1', 'c4ca4238a0b923820dcc509a6f75849b', '2019-05-01 06:33:27', 1),
(23, 'tester', 'tester@test.com', '49f68a5c8493ec2c0bf489821c21fc3b', '2019-05-01 19:13:56', 1),
(24, 'randalbl', 'randalbl@miamioh.edu', '2d0bb77f99342b239fac0a5a20703a45', '2019-05-01 23:36:50', 3),
(25, '12345', '12345@12344.5', '827ccb0eea8a706c4c34a16891f84e7b', '2019-05-01 23:39:50', 1);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `tblMovies`
--
ALTER TABLE `tblMovies`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `tblUsers`
--
ALTER TABLE `tblUsers`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `tblMovies`
--
ALTER TABLE `tblMovies`
  MODIFY `id` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=33;

--
-- AUTO_INCREMENT for table `tblUsers`
--
ALTER TABLE `tblUsers`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=26;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
