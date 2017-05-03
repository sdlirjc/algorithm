
#http://machinelearningmastery.com/tutorial-first-neural-network-python-keras/

#http://machinelearningmastery.com/save-load-keras-deep-learning-models/

import time
import numpy
import pickle

from keras.models import Sequential
from keras.layers import Dense
from keras.models import model_from_json


def test(model):

    # recompile loaded model
    model.compile(loss='binary_crossentropy', optimizer='rmsprop', metrics=['accuracy'])

    X, Y = load_data()

    # calculate predictions
    predictions = model.predict(X)
    # round predictions
    rounded = [round(x) for x in predictions]
    print(rounded)

    # evaluate the model
    scores = model.evaluate(X, Y)
    print("%s: %.2f%%" % (model.metrics_names[1], scores[1]*100))


def load_data():

    # fix random seed for reproducibility
    seed = 7 #time.time()7
    numpy.random.seed(seed)

    # load pima indians dataset
    dataset = numpy.loadtxt("pima-indians-diabetes.csv", delimiter=",")
    # split into input (X) and output (Y) variables
    X = dataset[:,0:8]
    Y = dataset[:,8]

    return X, Y


def train():
    X, Y = load_data()

    # create model
    model = Sequential()
    # input_dim is the feature number 8 
    #model.add(Dense(12, input_dim=8, init='uniform', activation='relu'))
    model.add(Dense(256, input_dim=8, init='uniform', activation='relu'))
    model.add(Dense(16, init='uniform', activation='relu'))
    model.add(Dense(1, init='uniform', activation='sigmoid'))

    # Compile model
    model.compile(loss='binary_crossentropy', optimizer='adam', metrics=['accuracy'])

    # Fit the model
    #model.fit(X, Y, nb_epoch=150, batch_size=10)
    model.fit(X, Y, nb_epoch=1000, batch_size=32, shuffle=True)

    # serialize model to JSON
    model_json = model.to_json()
    with open("model.json", "w") as json_file:
        json_file.write(model_json)
    # serialize weights to HDF5
    model.save_weights("model.h5")
    print("Saved model to disk")


def load():
    # load json and create model
    json_file = open('model.json', 'r')
    loaded_model_json = json_file.read()
    json_file.close()
    loaded_model = model_from_json(loaded_model_json)
    # load weights into new model
    loaded_model.load_weights("model.h5")
    print("Loaded model from disk")
    return loaded_model


def main():
    train()
    loaded_model = load()
    test(loaded_model)


if __name__ == "__main__":
    main()



# TODO try YAML format as well if necessary
