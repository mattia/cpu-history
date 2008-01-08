//
//  CPUUsageMonitor.h
//  CPU Usage
//
//  Created by Peter Hosey on 2006-06-21.
//  Copyright 2006 Peter Hosey. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#include <mach/mach.h>
#include <mach/processor_info.h>
#include <mach/mach_host.h>

typedef struct cpudata {
	double user;
	double sys;
	double nice;
	double idle;
} CPUData, CPUDataPtr*;

@interface CPUUsageMonitor : NSObject {
	processor_info_array_t lastProcessorInfo;
	mach_msg_type_number_t numLastProcessorInfo;
	unsigned numCPUs;
	float *CPUUsage;
	NSLock *CPUUsageLock, *deathLock;
	CPUDataPtr		cpudata;
}

- (cpudata)updateCPUUsage;



@end
