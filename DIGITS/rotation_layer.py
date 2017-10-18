#add this layer in DIGITS as a client side python layer while training the model 
import numpy as np
import caffe
import random

def doAugmenttion(img):
    return np.rot90(img, random.randrange(4))

class RotationLayer(caffe.Layer):
    def setup(self, bottom, top):
        assert len(bottom) == 1, 'requires a single layer.bottom'
        assert bottom[0].data.ndim >= 3, 'requires image data'
        assert len(top) == 1, 'requires a single layer.top'

    def reshape(self, bottom, top):
        # Copy shape from bottom
        top[0].reshape(*bottom[0].data.shape)

    def forward(self, bottom, top):
        # Copy all of the data
        top[0].data[...] = bottom[0].data[...]

        for ii in xrange(0, top[0].data.shape[0]):
            imin = top[0].data[ii, :, :, :].transpose(1, 2, 0)
            top[0].data[ii, :, :, :] = doAugmenttion(imin).transpose(2, 0, 1)

    def backward(self, top, propagate_down, bottom):
        pass






#add below layer in the customize section of googleNet in DIGITS
'''
    layer {
      name: "rotation_layer"
      type: "Python"
      bottom: "data"
      top: "data"
      include {
      phase: TRAIN
      }
      python_param {
        module: "digits_python_layers"
        layer: "RotationLayer"
      }
    }


'''
