
#ifndef SPI_config_H
#define SPI_config_H


#define  SLAVE_SELECT 		GPIOA,PIN0

#define SPI1_STATUS         SPI_ENABLE
	    
#define SPI1_CLOCK_MODE     SPI_MODE3
	    
#define SPI1_MASTER_SLAVE   SPI_MASTER
	    
#define SPI1_PRESCALLER     SPI_FPCLK_DIVIDED_BY_4
	    
#define SPI1_DATA_ORDER     SPI_MSB_FIRST
	    
#define SPI1_SS	   		    SW_SS
	    
#define SPI1_DATA_SIZE      SPI_8BIT_DATA
	    
#define SPI1_INT_STATUS     SPI_INT_DISABLE

#endif 
