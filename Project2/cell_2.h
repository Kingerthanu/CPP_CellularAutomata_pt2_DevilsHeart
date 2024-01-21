#ifndef CELL_2_H
#define CELL_2_H

#include "Vertex.h"
#include <glad/glad.h>

class Cell_Gen2
{

private:
	bool state = false;
	int offset;
	char NEIGHBORS_SIZE = 0;

public:
	bool** NEIGHBORS = nullptr;


	Cell_Gen2(const int& blockOffset)
	{

		this->offset = blockOffset;

	};

	void addNeighbor(Cell_Gen2& newNeighbor)
	{

		bool** tmp = new bool* [NEIGHBORS_SIZE + 1];

		for (int index = 0; index < this->NEIGHBORS_SIZE; index++) {

			tmp[index] = this->NEIGHBORS[index];

		}

		tmp[this->NEIGHBORS_SIZE++] = &newNeighbor.state;

		delete[] this->NEIGHBORS;

		this->NEIGHBORS = tmp;


	};

	float cnt = 0.0f;

	void think()
	{

		char amntAlive = 0;

		for (char i = 0; i < this->NEIGHBORS_SIZE; i++) {

			if (*this->NEIGHBORS[i] == true) {
				amntAlive++;
			}

		}

		bool prevState = this->state;

		// Sine wave modulation
		float sineValue = 0.48f * sin(offset * cnt);  // Adjust the frequency and amplitude as needed

		// Rules for wave propagation
		if (this->state) {
			// Deactivation rule for active cells
			if (amntAlive > 3 && ((rand() % 100) < 95) && sineValue >= -0.35f) {
				this->state = false;
			}
		}
		else {
			// Activation rule for inactive cells
			if ((amntAlive == 2) && (sineValue < -0.35f)) {
				this->state = true;
			}
		}

		cnt += 0.00000033333f;

	};


	void grabNeighbors(Cell_Gen2***& cells, const int& maxRow, const int& maxCol, const int& row, const int& col)
	{

		if (!(row & 1)) {

			if (row + 2 < maxRow) {

				this->addNeighbor(*cells[row + 2][col]);

			}

			if (row - 1 > -1) {

				this->addNeighbor(*cells[row - 1][col]);

				if (col - 1 > -1) {

					this->addNeighbor(*cells[row - 1][col - 1]);

				}

			}

			if (row - 2 > -1) {

				this->addNeighbor(*cells[row - 2][col]);

			}

			if (row + 1 < maxRow) {

				this->addNeighbor(*cells[row + 1][col]);

				if (col - 1 > -1) {

					this->addNeighbor(*cells[row + 1][col - 1]);

				}

			}

		}
		else {


			if (row + 2 < maxRow) {

				this->addNeighbor(*cells[row + 2][col]);

			}

			if (row - 1 > -1) {

				this->addNeighbor(*cells[row - 1][col]);

				if (col + 1 < maxCol) {

					this->addNeighbor(*cells[row - 1][col + 1]);

				}

			}

			if (row - 2 > -1) {

				this->addNeighbor(*cells[row - 2][col]);

			}

			if (row + 1 < maxRow) {

				this->addNeighbor(*cells[row + 1][col]);

				if (col + 1 < maxCol) {

					this->addNeighbor(*cells[row + 1][col + 1]);

				}

			}


		}

	};

	void spark()
	{

		this->state = true;

	};

	void turnOn(Vertex*& bufferData)
	{



		// Update all vertices in the buffer
		for (int i = this->offset, newOffset = this->offset + 6; i < newOffset; ++i) {
			if (this->state && bufferData[i].color.r <= 1.0f) {
				bufferData[i].color += glm::vec3(0.085f, 0.0045f, 0.00042f);  // Equivalent to += bufferData[i].color;
			}
			else {
				bufferData[i].color *= 0.0f;
			}
		}

	};
};
#endif
