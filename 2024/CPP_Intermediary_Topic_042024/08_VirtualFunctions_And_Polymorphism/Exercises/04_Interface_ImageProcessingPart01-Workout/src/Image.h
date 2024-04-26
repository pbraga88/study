#pragma once

class Image
{
	int brightness {0};
	int contrast {0};
	int edgeEnhancement {0};
public:
	Image(void);
	~Image(void);

	void setBright();
	void setContrast();
	void setEdge();

	int getBright();
	int getContrast();
	int getEdge();
};
