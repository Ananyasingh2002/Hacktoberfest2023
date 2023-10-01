package database

import (
	"os"

	"github.com/joho/godotenv"
	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)

var DB *gorm.DB

func InitDatabase() {
	err := error(nil)
	env := godotenv.Load()

	if env != nil {
		panic("Error loading .env file")
	}

	DB_HOST := os.Getenv("DB_HOST")
	DB_PORT := os.Getenv("DB_PORT")
	DB_USER := os.Getenv("DB_USER")
	DB_NAME := os.Getenv("DB_NAME")
	DB_PASSWORD := os.Getenv("DB_PASSWORD")
	DB_SSL_MODE := os.Getenv("DB_SSL_MODE")

	dsn := "host= " + DB_HOST + " " + "user=" + DB_USER + " " + " password=" + DB_PASSWORD + " " + " dbname=" + DB_NAME + " " + " port=" + DB_PORT + " " + "sslmode=" + DB_SSL_MODE
	DB, err = gorm.Open(postgres.Open(dsn), &gorm.Config{})

	if err != nil {
		panic("Failed to connect to database!")
	}
}
