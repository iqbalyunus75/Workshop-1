-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 28, 2020 at 09:48 AM
-- Server version: 10.4.11-MariaDB
-- PHP Version: 7.2.31

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `dbmusic`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin_table`
--

CREATE TABLE `admin_table` (
  `admin_id` varchar(50) NOT NULL,
  `admin_password` varchar(50) NOT NULL,
  `admin_fname` varchar(50) NOT NULL,
  `admin_lname` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `admin_table`
--

INSERT INTO `admin_table` (`admin_id`, `admin_password`, `admin_fname`, `admin_lname`) VALUES
('AD001', 'admin', 'Ali', 'Baba');

-- --------------------------------------------------------

--
-- Table structure for table `album_table`
--

CREATE TABLE `album_table` (
  `album_id` int(50) NOT NULL,
  `album_title` varchar(50) NOT NULL,
  `album_artist` varchar(50) NOT NULL,
  `album_genre` varchar(50) NOT NULL,
  `album_price` varchar(50) NOT NULL,
  `album_quantity` int(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `album_table`
--

INSERT INTO `album_table` (`album_id`, `album_title`, `album_artist`, `album_genre`, `album_price`, `album_quantity`) VALUES
(1, 'Lagu Kanak - Kanak', 'Aisyah', 'Fun', '10', 78),
(2, 'Lagu Dewasa', 'Mamat', 'Rock', '20', 90),
(3, 'Lagu Remaja', 'Fikry', 'Pop', '15', 92);

-- --------------------------------------------------------

--
-- Table structure for table `manager_table`
--

CREATE TABLE `manager_table` (
  `manager_id` varchar(50) NOT NULL,
  `manager_password` varchar(50) NOT NULL,
  `manager_fname` varchar(50) NOT NULL,
  `manager_lname` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `manager_table`
--

INSERT INTO `manager_table` (`manager_id`, `manager_password`, `manager_fname`, `manager_lname`) VALUES
('M001', '1234', 'Iqbal', 'Yunus');

-- --------------------------------------------------------

--
-- Table structure for table `soldalbum_table`
--

CREATE TABLE `soldalbum_table` (
  `album_id` int(50) NOT NULL,
  `album_title` varchar(50) NOT NULL,
  `album_artist` varchar(50) NOT NULL,
  `album_genre` varchar(50) NOT NULL,
  `album_price` varchar(50) NOT NULL,
  `album_quantity` int(50) NOT NULL,
  `album_solddate` date NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `soldalbum_table`
--

INSERT INTO `soldalbum_table` (`album_id`, `album_title`, `album_artist`, `album_genre`, `album_price`, `album_quantity`, `album_solddate`) VALUES
(0, 'Lagu Kanak - Kanak', 'Aisyah', 'Fun', '10', 1, '0000-00-00'),
(0, 'Lagu Dewasa', 'Mamat', 'Rock', '20', 1, '0000-00-00'),
(0, 'Lagu Kanak - Kanak', 'Aisyah', 'Fun', '10', 1, '0000-00-00'),
(0, 'Lagu Dewasa', 'Mamat', 'Rock', '20', 1, '0000-00-00'),
(0, 'Lagu Kanak - Kanak', 'Aisyah', 'Fun', '10', 1, '0000-00-00'),
(0, 'Lagu Dewasa', 'Mamat', 'Rock', '20', 1, '0000-00-00'),
(0, 'Lagu Kanak - Kanak', 'Aisyah', 'Fun', '10', 1, '2020-06-01'),
(0, 'Lagu Kanak - Kanak', 'Aisyah', 'Fun', '10', 1, '2020-06-01'),
(0, 'Lagu Kanak - Kanak', 'Aisyah', 'Fun', '10', 1, '2020-06-01'),
(0, 'Lagu Kanak - Kanak', 'Aisyah', 'Fun', '10', 1, '2020-06-09'),
(0, 'Lagu Dewasa', 'Mamat', 'Rock', '20', 1, '2020-06-09'),
(0, 'Lagu Kanak - Kanak', 'Aisyah', 'Fun', '10', 1, '2020-06-09'),
(0, 'Lagu Kanak - Kanak', 'Aisyah', 'Fun', '10', 1, '2020-06-09'),
(0, 'Lagu Kanak - Kanak', 'Aisyah', 'Fun', '10', 1, '2020-06-27'),
(0, 'Lagu Dewasa', 'Mamat', 'Rock', '20', 1, '2020-06-27'),
(0, 'Lagu Kanak - Kanak', 'Aisyah', 'Fun', '10', 1, '2020-06-28'),
(0, 'Lagu Remaja', 'Fikry', 'Pop', '15', 1, '2020-06-28'),
(0, 'Lagu Remaja', 'Fikry', 'Pop', '15', 1, '2020-06-28');

-- --------------------------------------------------------

--
-- Table structure for table `staff_table`
--

CREATE TABLE `staff_table` (
  `staff_id` varchar(50) NOT NULL,
  `staff_password` varchar(50) NOT NULL,
  `staff_fname` varchar(50) NOT NULL,
  `staff_lname` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `staff_table`
--

INSERT INTO `staff_table` (`staff_id`, `staff_password`, `staff_fname`, `staff_lname`) VALUES
('S001', '1234', 'Aminah', 'Wahab'),
('S002', '1234', 'Rosli', 'Roslan'),
('S003', '1234', 'Abu', 'Bakar');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin_table`
--
ALTER TABLE `admin_table`
  ADD PRIMARY KEY (`admin_id`);

--
-- Indexes for table `album_table`
--
ALTER TABLE `album_table`
  ADD PRIMARY KEY (`album_id`);

--
-- Indexes for table `manager_table`
--
ALTER TABLE `manager_table`
  ADD PRIMARY KEY (`manager_id`);

--
-- Indexes for table `staff_table`
--
ALTER TABLE `staff_table`
  ADD PRIMARY KEY (`staff_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `album_table`
--
ALTER TABLE `album_table`
  MODIFY `album_id` int(50) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
