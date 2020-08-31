/*
 * gust_shm_dirver.c
 *
 *  Created on: Aug 31, 2020
 *      Author: jeken
 */

#include  <linux/kernel.h>
#include  <linux/of_device.h>
#include  <linux/module.h>
#include  <linux/platform_device.h>
#include  <linux/init.h>
#include  <linux/uaccess.h>
#include  <linux/atomic.h>

#include "guest_shm.h"

struct shm_data {
	volatile struct guest_shm_factory *g_factory;
	volatile struct guest_shm_control *g_ctrl;
	struct tasklet_struct tasklet;
	unsigned char *shmdata;
	int irq;
};

static int shmem_probe(struct platform_device *pdev){



	return 0;
}

static struct of_device_id shmem_of_match[] = {
		{.compatible  =  "agl,hqx_shmem"},
		{}
};


static struct platform_driver shmem_pdriver = {
		.probe = shmem_probe,
		.driver = {
				.name = "hqx_shmem",
				.of_match_table = shmem_of_match,
		},
};


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jeken ZHUANG");
MODULE_DESCRIPTION("Sharing memory between Host and Guest");
MODULE_VERSION("0.1");
